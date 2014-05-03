#include "stdafx.h"
#include "Client.h"
#include <stdexcept>


#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdio>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

using namespace std;


	WSADATA wsaData;
    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

	const char* DEFAULT_PORT = "27015";
#define DEFAULT_BUFLEN 256
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;

    int iResult = 0;
    int iSendResult = 0;

namespace ClientDll
{

	int DsauClient::mkConnection(string ServerAddress)
	{

		// Initialize Winsock
		iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
		if (iResult != 0) {
			printf("WSAStartup failed with error: %d\n", iResult);
			return 1;
		}

		ZeroMemory(&hints, sizeof(hints));
/*		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;
		*/
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		//caddr;
		// Resolve the server address and port
		iResult = getaddrinfo(ServerAddress.c_str(), DEFAULT_PORT, &hints, &result);
		if ( iResult != 0 ) {
			printf("getaddrinfo failed with error: %d\n", iResult);
			WSACleanup();
			return 1;
		}

		// Attempt to connect to an address until one succeeds
		for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

			// Create a SOCKET for connecting to server
			ClientSocket = socket(ptr->ai_family, ptr->ai_socktype,
				ptr->ai_protocol);
			if (ClientSocket == INVALID_SOCKET) {
				printf("socket failed with error: %ld\n", WSAGetLastError());
				WSACleanup();
				return 1;
			}

			int recBuf = 1048576;
			int delayFlag = 0;
			int routeFlag = 1;
			int clamp = 524288;

			setsockopt(ClientSocket, SOL_SOCKET, SO_RCVBUF, (char*)&recBuf, sizeof(recBuf));

//			setsockopt(ClientSocket, SOL_SOCKET, SO_DONTROUTE, (char*)&routeFlag, sizeof(routeFlag));
//			setsockopt(ClientSocket, IPPROTO_TCP, TCP_NODELAY, (char*)&delayFlag, sizeof(delayFlag));
//			setsockopt(ClientSocket, IPPROTO_TCP, TCP_WINDOW_CLAMP, &clamp, sizeof(clamp));
			// Connect to server.
			iResult = connect( ClientSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
			if (iResult == SOCKET_ERROR) {
				closesocket(ClientSocket);
				ClientSocket = INVALID_SOCKET;
				//continue;
				return 1;
			}
			break;
		}
		freeaddrinfo(result);
	}



	int DsauClient::rmConnection()
	{
		// shutdown the connection since we're done
		iResult = shutdown(ClientSocket, SD_SEND);
		if (iResult == SOCKET_ERROR) {
			printf("shutdown failed with error: %d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();
			return 1;
		}

		// cleanup
		closesocket(ClientSocket);
		WSACleanup();

	}

	int DsauClient::sendThis(string msgstring)
	{
		//convert string to char
//		char *cinstr=new char[msgstring.size()+1];
		char cinstr[DEFAULT_BUFLEN];//=new char[msgstring.size()+1];
		cinstr[msgstring.size()]=0;
		memcpy(cinstr,msgstring.c_str(),msgstring.size());	
//		char *recvbuf = new char[DEFAULT_BUFLEN];
		char recvbuf[DEFAULT_BUFLEN];// = new char[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN; 
		// Receive until the peer shuts down the connection
		do {
			//send the command/instruction to server
			iSendResult = send( ClientSocket, cinstr, msgstring.size()+1, 0 );
			if (iSendResult == SOCKET_ERROR) {
				printf("send failed with error: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}

/*			iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
			if (iResult > 0) {

				//		printf("Bytes received: %s\n", recvbuf);
				if(recvbuf[0] == 'e')
				{
					//Msg is wrong, exit with error code
					printf("Invalid intruction input");
				}
				else if(recvbuf[0] =='f')
				{       printf("Recv complete. Connection closing...\n");			}
				else{}

			}
			else if (iResult == 0)
				printf("Connection closing...\n");
			else  {
				printf("recv failed with error: %d\n", WSAGetLastError());
				return 1;
			}
*/
//			std::this_thread::sleep_for(std::chrono::nanoseconds(100));

//DO NOT REMOVE ME
//YAH. IM LOOKING AT YOU.
			volatile int k=0;
//YOU BETTER NOT
			for (int p=0; p<999999; p++) {
				k += p*k;
			}
//REMOVE ME
//Explanation: we need to do an operation to take up some time or the GUI crashes
			recvbuf[0] = 'f';
		} while (iResult > 0 && (recvbuf[0] !='e' && recvbuf[0] !='f') );

	}
#include <stdint.h>
int DsauClient::recvThis()
{
			int ret = 0; int num = 0;
//			char *recvbuf = new char[DEFAULT_BUFLEN];
			char recvbuf[DEFAULT_BUFLEN];
//			char recvbuf[6553600];
			int recvbuflen = DEFAULT_BUFLEN; 
			//Open File for data storage
			ofstream ofile("fwrite_test", ios::out | ios::binary );
//			FILE *pFile;
			int index;
//			pFile = fopen("ofwrite_test.txt", "wb");
			//ofstream outFile;
			//outFile.open("fwrite_test.txt");//, "wb");
			char data[DEFAULT_BUFLEN];
			// Receive until the peer shuts down the connection
//			memset(recvbuf, 0, DEFAULT_BUFLEN);
			int counter=0;
			do {
//			while(1) {
				iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
				counter+=iResult;
//				if (counter >= 13107200) {
//					break;
//				}
				if (iResult > 0) {
					ofile.write(recvbuf, iResult);
					counter += recvbuf[1];
				}
//				else if (iResult == 0)
//					printf("Connection closing...\n");
				else  {
//					printf("recv failed with error: %d\n", WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					return 1;
				}
	} while (iResult > 0);
		//		fclose(pFile);
		ofile.close();
		return ret;
	}
	int DsauClient::saveThis(char* fileSaveName)
	{
		int ret = 0; int num = 0;
		char recvbuf[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN; 
		//Open File for data storage
		ofstream ofile(fileSaveName, ios::out | ios::binary );

		int index;
		int rcount = 0;
		char data[DEFAULT_BUFLEN];
		// Receive until the peer shuts down the connection
		memset(recvbuf, 0, DEFAULT_BUFLEN);
		int counter=0;
		do {
			rcount++;
			iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
			if (iResult > 0) {
				ofile.write(recvbuf, iResult);			
			}
			else if (iResult == 0)
				printf("Connection closing...\n");
			else  {
				printf("recv failed with error: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
		} while (iResult > 0);
		//		fclose(pFile);
		ofile.close();
		return ret;
	}

	//Add auto error reconnection handling
}
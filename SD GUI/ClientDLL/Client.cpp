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
	int DEFAULT_BUFLEN = 512;
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
		char *cinstr=new char[msgstring.size()+1];
		cinstr[msgstring.size()]=0;
		memcpy(cinstr,msgstring.c_str(),msgstring.size());	
		char *recvbuf = new char[DEFAULT_BUFLEN];
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
			iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
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
			
		} while (iResult > 0 && (recvbuf[0] !='e' && recvbuf[0] !='f') );

	}
int DsauClient::recvThis()
{
	int ret = 0; int num = 0;
			char *recvbuf = new char[DEFAULT_BUFLEN];
			int recvbuflen = DEFAULT_BUFLEN; 
			//Open File for data storage
			ofstream ofile("fwrite_test", ios::out | ios::binary );
//			FILE *pFile;
			int index;
//			pFile = fopen("ofwrite_test.txt", "wb");
			//ofstream outFile;
			//outFile.open("fwrite_test.txt");//, "wb");
			int rcount = 0;
			// Receive until the peer shuts down the connection
			do {
				rcount++;
				 memset(recvbuf, 0, DEFAULT_BUFLEN);
				iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
				if (iResult > 0) {
/*					for (int i=0; i<DEFAULT_BUFLEN; i++)
					{
						printf("%x,",recvbuf[i]);
						if (i == 198)
						{
							int j = 1;
						}
					}
*/						//OutputDebugString("kjhlk");
						//System.Diagnostics("%x,",recvbuf[i]);
printf("\n");
//						fwrite (recvbuf , sizeof(uint16_t),DEFAULT_BUFLEN , pFile);
						ofile.write(recvbuf, iResult);
						//outFile.write(recvbuf, sizeof(recvbuf));// << recvbuf << endl;
//					}
				}
				else if (iResult == 0)
					printf("Connection closing...\n");
				else  {
					printf("recv failed with error: %d\n", WSAGetLastError());
					closesocket(ClientSocket);
					WSACleanup();
					return 1;
				}
				for (int i=0; i<DEFAULT_BUFLEN; i++)
				{
					if((recvbuf[i] == 102)  )
					{	
						if(recvbuf[i+1] == 102)
						{
							if(recvbuf[i+2] == 102)
							{
								if(recvbuf[i+3] == 102)
								{
									if(recvbuf[i+4] == 102)
									{		
										if(ret == 0)
										{
											int temp = 512*rcount;
											ret = temp - 512 + i;//this is wrong
										}
										iResult = 0;
									}
								}
							}
						}

					}
				}

		} while (iResult > 0);
		//		fclose(pFile);
		ofile.close();
		return ret;
	}
/*
	int DsauClient::recvThis()
	{
		char *recvbuf = new char[DEFAULT_BUFLEN];
//		int irecvbuf = new int[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN; 
		//Open File for data storage
		FILE *pFile;
		int index;
		pFile = fopen("fwrite_test.txt", "w");
		//ofstream outFile;
		//outFile.open("fwrite_test.txt");//, "wb");
		int ntest;
		// Receive until the peer shuts down the connection
		do {
			memset(recvbuf, 0, DEFAULT_BUFLEN);
			iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
//			ntest= ntohl(recvbuf);
			if (iResult > 0) {
				//		printf("Bytes received: %s\n", recvbuf);
				if(recvbuf[0] =='b')
				{
					fwrite (recvbuf , sizeof(char), sizeof(recvbuf), pFile);
					memset(recvbuf, 0, 512);
				}
				else if(recvbuf[0] =='f')
				{       
					printf("Recv complete. Connection closing...\n");			
				}
				else{
					
					fwrite (recvbuf , sizeof(char), DEFAULT_BUFLEN, pFile);
					//outFile.write(recvbuf, sizeof(recvbuf));// << recvbuf << endl;

				}
			}
			else if (iResult == 0)
				printf("Connection closing...\n");
			else  {
				printf("recv failed with error: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
////			for (int i = 0; i < 512; i++)
	//		{
				//if(recvbuf[i] == 'f')
				//{
				//	iResult = 0;
				//	i = 512;
				//	//break;
				//}
				if(recvbuf[iResult-3] == 'f')
				{	
					iResult = 0;
				}

	///		}

		} while (iResult > 0 && recvbuf[iResult-3] !='f');
		fclose(pFile);
	}
	*/
	int DsauClient::saveThis(char* fileSaveName)
	{
		char *recvbuf = new char[DEFAULT_BUFLEN];
		int recvbuflen = DEFAULT_BUFLEN; 
		//Open File for data storage
		FILE *pFile;
		int index;
		pFile = fopen(fileSaveName, "w");
		//ofstream outFile;
		//outFile.open("fwrite_test.txt");//, "wb");

		// Receive until the peer shuts down the connection
		do {
			memset(recvbuf, 0, DEFAULT_BUFLEN);
			iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
			if (iResult > 0) {
				//		printf("Bytes received: %s\n", recvbuf);
				if(recvbuf[0] =='b')	
				{
					fwrite (recvbuf , sizeof(char), sizeof(recvbuf), pFile);
					memset(recvbuf, 0, 512);
				}
				else if(recvbuf[iResult] =='f')
				{       
					printf("Recv complete. Connection closing...\n");			
				}
				else{
					fwrite (recvbuf , sizeof(char), DEFAULT_BUFLEN, pFile);
					//outFile.write(recvbuf, sizeof(recvbuf));// << recvbuf << endl;

				}
			}
			else if (iResult == 0)
				printf("Connection closing...\n");
			else  {
				printf("recv failed with error: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}

				if(recvbuf[iResult-3] == 'f')
				{	
					iResult = 0;
				}


		} while (iResult > 0 && recvbuf[iResult-3] !='f');
		fclose(pFile);
	}


	//Add auto error reconnection handling
}

#include "stdafx.h"
//#ifndef CLIENT
//#define CLIENT
//
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
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
 //   memset(recvbuf, 0, 512);

int mkConnection(string caddr)
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
	
    // Resolve the server address and port
    iResult = getaddrinfo(caddr, DEFAULT_PORT, &hints, &result);
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
            continue;
        }
        break;
    }
	freeaddrinfo(result);

}

int rmConnection()
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

int sendThis(string msgstring)
{
	//convert string to char
	char *cinstr=new char[msgstring.size()+1];
	cinstr[msgstring.size()]=0;
	memcpy(cinstr,msgstring.c_str(),msgstring.size());	
 
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

    } while (iResult > 0 && (recvbuf[0] !='e' || recvbuf[0] !='f') );

}

int recvThis()
{

	//Open File for data storage
	FILE * pFile;
	pFile = fopen ("fwrite_test.txt", "wb");
    
    // Receive until the peer shuts down the connection
	do {

		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		if (iResult > 0) {
	//		printf("Bytes received: %s\n", recvbuf);
			if(recvbuf[0] =='b')
			{
			fwrite (recvbuf , sizeof(char), sizeof(recvbuf), pFile);
			memset(recvbuf, 0, 512);
			}
			else if(recvbuf[0] !='f')
			{       printf("Recv complete. Connection closing...\n");			}
			else{}
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else  {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }



    } while (iResult > 0 && recvbuf[0] !='f');

}
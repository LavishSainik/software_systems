/*
============================================================================
Name : 33a.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to communicate between two machines using socket.
Date: 19th Oct, 2023.
============================================================================
*/
//server
#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int serverSocket, newSocket;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;

    // Create the socket
    serverSocket = socket(PF_INET, SOCK_STREAM, 0);

    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Choose a port
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address
    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

    // Listen for incoming connections
    listen(serverSocket, 5);

    addr_size = sizeof(serverStorage);
    newSocket = accept(serverSocket, (struct sockaddr*)&serverStorage, &addr_size);

    // Receive data from the client
    char buffer[1024];
    recv(newSocket, buffer, sizeof(buffer), 0);
    std::cout << "Received from client: " << buffer << std::endl;

    close(newSocket); // Close the socket
    close(serverSocket);

    return 0;
}

/*
============================================================================
Name : 33b.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to communicate between two machines using socket.
Date: 19th Oct, 2023.
============================================================================
*/
//client
#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;

    // Create the socket
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);

    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Use the same port as the server
    serverAddr.sin_addr.s_addr = inet_addr("SERVER_IP_ADDRESS"); // Replace with the server's IP address

    // Connect to the server
    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr);

    // Send data to the server
    std::string message = "Hello, Server!";
    send(clientSocket, message.c_str(), message.size(), 0);

    close(clientSocket); // Close the socket

    return 0;
}

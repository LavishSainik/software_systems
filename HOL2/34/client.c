/*
============================================================================
Name : client.c
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to create a concurrent server.    a. use fork    b. use pthread_create
Date: 19th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define PORT 8888

void main() {
    struct sockaddr_in serv;
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(PORT);
    connect(sd, (struct sockaddr *)&serv, sizeof(serv));
    char buf[1024]={0};
    send(sd, "Hello, This is Client!\n", 24, 0);
    recv(sd, buf, sizeof(buf), 0);
    printf("%s", buf);
}
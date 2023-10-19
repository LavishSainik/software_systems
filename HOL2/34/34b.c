/*
============================================================================
Name : 34b.c
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to create a concurrent server.    a. use fork    b. use pthread_create
Date: 19th Oct, 2023.
============================================================================
*/
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>
#define PORT 8888

void *Thread(void *sd) {
    int nsd = *(int *)sd;
    char buffer[1024];
    read(nsd, buffer, sizeof(buffer));
    printf("%s\n", buffer);
    char *msg = "Hi";
    write(nsd, msg, strlen(msg));
    printf("Client Acknowledged\n");
}

void main() {
    struct sockaddr_in socket_address;
    int opt = 1;
    int len = sizeof(socket_address);
    char buffer[1024];
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    socket_address.sin_family = AF_INET;
    socket_address.sin_addr.s_addr = INADDR_ANY;
    socket_address.sin_port = htons(PORT);
    bind(sd, (struct sockaddr *)&socket_address, sizeof(socket_address));
    listen(sd, 1);
    pthread_t clients;
    while (1) {
        int nsd = accept(sd, (struct sockaddr *)&socket_address, (socklen_t *)&len);
        pthread_create(&clients, NULL, Thread, (void *)&nsd);
        exit(EXIT_SUCCESS);
    }
}
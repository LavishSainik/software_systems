/*
============================================================================
Name : 34a.c
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
#define PORT 8888

void main(void) {
	int server_fd, nsd, valread;
	struct sockaddr_in socket_address;
	int opt = 1;
	int addrlen = sizeof(socket_address);
	char buffer[1024] = {0};
	char *hello = "Hi\0";
	if(!(server_fd = socket(AF_INET, SOCK_STREAM, 0))) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	socket_address.sin_family = AF_INET;
	socket_address.sin_addr.s_addr = INADDR_ANY;
	socket_address.sin_port = htons(PORT);
	if(bind(server_fd, (struct sockaddr *)&socket_address, sizeof(socket_address)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if(listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
	while(1) {
		if((nsd = accept(server_fd, (struct sockaddr *)&socket_address, (socklen_t *)&addrlen)) < 0) {
			perror("accept");
			exit(EXIT_FAILURE);
		}
		pid_t pid;
		if((pid=fork()) == -1) {
			perror("Fork");
			exit(EXIT_FAILURE);
		}
		if(!pid) {
			char buf[1024];
			close(server_fd);
			read(nsd, buf, sizeof(buf));
			printf("%s\n", buf);
			send(nsd, hello, 2, 0);
			printf("Hello message sent\n");
			exit(EXIT_SUCCESS);
		}
		else{
			printf("Inside parent!\n");
			close(nsd);
			int returnStatus;
			waitpid(pid, &returnStatus, 0);
			if(!returnStatus)
				exit(EXIT_SUCCESS);
			else {
				printf("Child not exited normally\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}
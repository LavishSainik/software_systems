/*
========================================================================================
Name : 15.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a simple program to send some data from parent to the child process
Date: 19th October, 2023
========================================================================================
*/
#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
   int fdofpipe[2];

   if(pipe(fdofpipe)==-1){
      perror("pipe");
      return 1;
   }
   pid_t pid = fork();

   if(pid==-1){
      perror("fork");
      return 1;
   }

   if(pid==0){
     close(fdofpipe[1]);   //close the write end of the pipe
     char buffer[256];
     ssize_t bytes_read = read(fdofpipe[0],buffer,sizeof(buffer));
     if(bytes_read>0){
          buffer[bytes_read]='\0';  //NULL terminate string
          cout<<"Child recieved: "<<buffer<<endl;
     }
     close(fdofpipe[0]);

   }
   else{
     close(fdofpipe[0]); //close the read end of the pipe
    const char* message = "Data from parent ";
    ssize_t bytes_to_write= write(fdofpipe[1],message,strlen(message));
    if(bytes_to_write==-1){
         perror("write");
	 return 1;
    }
    close(fdofpipe[1]);
   }



return 0;}

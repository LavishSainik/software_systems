/*
=====================================================================================
Name : 18.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to find out total number of directories on the pwd.
            execute ls -l | grep ^d | wc ? Use only dup2
Date: 19th October, 2023
=====================================================================================
*/
#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<fcntl.h>
using namespace std;

int main(){

   int pipe_fd[2];

   if(pipe(pipe_fd) == -1){
     perror("pipe creation");
     return 1;
   }

   pid_t pid=fork();
   if(pid==-1){
     perror("fork failed");
     return 1;
   }

   if(pid ==0){
       close(pipe_fd[0]);
       dup2(pipe_fd[2],STDOUT_FILENO);
       execlp("ls","ls","-l",NULL);
   }
   else{
      close(pipe_fd[1]);
      pid_t pid2 = fork();
      if(pid2==-1){
         perror("fork");
	 return 1;
      }

      if(pid2==0){
      //2nd child process
        dup2(pipe_fd[0],STDIN_FILENO);
	execlp("grep","grep","^d",NULL);
      }
      else{
         close(pipe_fd[0]);
	 pid_t pid3=fork();
	 if(pid3==0){
	    int fd = open("output.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	    dup2(fd,STDOUT_FILENO);
	    execlp("wc","wc","-l",NULL);
	 }
	 else{
	   waitpid(pid2,NULL,0);
	   waitpid(pid3,NULL,0);
	 }
      }
   }





return 0;}

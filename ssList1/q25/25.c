/*
============================================================================
Name : 25.c
Author : Lavish Sainik
Description : Program to create three child process. Parent should wait for a perticular child.
Date: 8th sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main() {
  pid_t child1;
  pid_t child2;
  pid_t child3;
  if(!(child1 = fork())) {
    printf("Child 1 sleeps for 2s\n");
    sleep(2);
    printf("Child 1 awake after 2s\n");
  }
  else if(!(child2=fork())) {
    printf("Child 2 sleeps for 4s\n");
    sleep(4);
    printf("Child 2 awake after 4s\n");
  }
  else if(!(child3=fork())) {
    printf("Child 3 sleeps for 8s\n");
    sleep(8);
    printf("Child 3 awake after 8s\n");
  }
  else {
    waitpid(child2, NULL, 0);
    printf("Parent waiting for child 1\n");
  }
}

/*
============================================================================
Name : 1c.c
Author : Lavish Sainik
Description : Create the following types of a files using 
              (i) shell command (ii) system call
              c. FIFO (mkfifo Library Function or mknod system call)
Date: 19 August, 2023
============================================================================
*/

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int my_fifo(const char* path, mode_t mode) {
  return mkfifo(path, mode);
}

void main() {
  const char* path="/tmp/fifo";
  mode_t mode=0666;
  printf("%d\n", my_fifo(path, mode));
}

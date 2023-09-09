/*
============================================================================
Name : 4.c
Author : Lavish Sainik
Description : program to open a existing file in read write mode.
Date: 7th Sep, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
   
   int fd;
   fd=open("toopen.text",O_RDWR);
   printf("%d",fd);


   return 0;}

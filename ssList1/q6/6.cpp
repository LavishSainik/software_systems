/*
============================================================================
Name : 6.cpp
Author : Lavish Sainik
Description : program to take input from STDIN  and display on STDOUT.
Date: 7th Sep, 2023.
============================================================================
*/


#include<iostream>
#include<unistd.h>
using namespace std;
#include<fcntl.h>

int main(){

   const int buff_size = 1024;
   char buff[buff_size];
   int byread;

   byread=read(0,buff,sizeof(buff));

   if(byread==-1){
    perror("read failure");
    return 1;
   }

   int bywritten = write(1,buff,byread);
   if(bywritten == -1){
       perror("write failure");
       return 1;
   }




return 0;}

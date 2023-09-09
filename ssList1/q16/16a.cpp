/*
============================================================================
Name : 16a.cpp
Author : Lavish Sainik
Description : program to implement a write lock , mandatory locking
Date: 9th sep, 2023.
============================================================================
*/

#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;


int main(){

   const char* path = "write_lock.cpp";

   
    int fd = open(path,O_WRONLY | O_CREAT,0644);
   
   struct flock lock;
   lock.l_type = F_WRLCK;
   lock.l_start=0;
   lock.l_whence=SEEK_SET;
   lock.l_len=0;

   if(fcntl(fd,F_SETLKW,&lock)==-1){
      perror("acquiring write lock");
      return 0;\
   }
   cout<<"write lock acquired"<<endl;

   lock.l_type=F_UNLCK;
   if(fcntl(fd,F_SETLKW,&lock)==-1){
       perror("Relesasing write lock");
   }
   close(fd);


 return 0;}

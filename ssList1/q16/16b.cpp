/*
============================================================================
Name : 16b.cpp
Author : Lavish sainik
Description : Program to implement a read lock , mandatory locking
Date: 8th sep, 2023.
============================================================================
*/


#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int main(){

   const char* path = "read_lock.cpp";

   int fd =open(path,O_RDONLY);
   struct flock lock;
   lock.l_type=F_RDLCK;
   lock.l_start=0;
   lock.l_whence=SEEK_SET;
   lock.l_len=0;

   if(fcntl(fd,F_SETLKW,&lock)==-1){
        perror("acquiring read lock");
	return 0;
   }
   cout<<"Read lock acquired"<<endl;

   lock.l_type=F_UNLCK;
   if(fcntl(fd,F_SETLKW,&lock)==-1){
       perror("releasing read lock");
       return 0;
   }
   cout<<"locks released";
   close(fd);



return 0;}

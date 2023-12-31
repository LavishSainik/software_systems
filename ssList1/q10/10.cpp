/*
============================================================================
Name : 10.cpp
Author : Lavish Saink
Description : program to open a file, write 10 bytes, move the file pointer by 10 bytes using lseek and check the return value of it.
Date: 28th Aug, 2023.
============================================================================
*/


#include<iostream>
#include<fcntl.h>
using namespace std;
#include<unistd.h>
int main(){

   int fd;

   fd =open("test2",O_RDWR);
   if(fd == -1){
   perror("error");
   return 1;
   }
   const char data1[] ="1234567890";
   const char data2[]="abcdefghij";

   write(fd,data1,sizeof(data1)-1);
   
  off_t seek = lseek(fd,10,SEEK_CUR);
  write(fd,data2,sizeof(data2)-1);
  close(fd);
  cout<<seek<<endl;
  

return 0;}

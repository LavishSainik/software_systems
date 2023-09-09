/*
============================================================================
Name : 12.cpp
Author : Lavish Sainik
Description : program to find out opening mode of file using fcntl
Date: 7th sep, 2023.
============================================================================
*/

#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;


int main(){

 const char* path="12.cpp";

 int fd = open(path,O_RDONLY);

 if(fd==-1){
   cout<<"failed to open file"<<endl;
   return 0;
 }

 int flags = fcntl(fd,F_GETFL);

 if( (flags & O_RDONLY) && (flags & O_WRONLY) ){
     cout<<"file is open in both read and write mode";
 }
 else if(flags & O_RDONLY){
     cout<< "file is open in read only mode";
 }
 else if(flags & O_WRONLY){
    cout<<"file is open in write only mode";
 }
 else{
    cout<<"file is open in unknown mode";
 }


return 0;}


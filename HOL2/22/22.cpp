/*
============================================================================
Name : 22.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description :  Write a program to wait for data to be written into FIFO within 10 seconds, use select 
system call with FIFO.
Date: 19th Oct, 2023.
============================================================================
*/
#include<iostream>
#include<cstring>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/select.h>
using namespace std;
int main(){
  
    const char *fifopath = "tmp/myfifo";
   struct stat statBuf;
    if (stat(fifopath, &statBuf) == -1) {
        if (mkfifo(fifopath, 0666) == -1) {
            std::cerr << "Failed to create FIFO: " << strerror(errno) << std::endl;
            return 1;
        }
    }
    int fifofd=open(fifopath,O_RDONLY);
    if(fifofd==-1){
        perror("failed to open fifo");
        return 1;
    }
    struct timeval timeout;
    timeout.tv_sec=10;
    timeout.tv_usec=0;

    fd_set readFds;
    FD_ZERO(&readFds);
    FD_SET(fifofd,&readFds);

    int ready=select(fifofd+1,&readFds,nullptr,nullptr,&timeout);
    if(ready==-1){
        perror("select failed");
    }
    else if(ready==0){
        cout<<"timeout reached,No data available in fifo"<<endl;

    }
    else{
        if(FD_ISSET(fifofd,&readFds)){
            char buffer[1024];
            ssize_t bytesRead = read(fifofd,buffer,sizeof(buffer));   
        
        if(bytesRead>0){
            buffer[bytesRead]='\0';
            cout<<"Recieved message"<< buffer<<endl;      
        }
        else{
            perror("Failed to read data from fifo");
        }
        
        }
    }
    close(fifofd);


    return 0;
}
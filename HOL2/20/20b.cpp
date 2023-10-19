/*
============================================================================
Name : 20b.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description :  Write two programs so that both can communicate by FIFO -Use one way communications. 
Date: 19th Oct, 2023.
============================================================================
*/
#include<iostream>
#include<cstring>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
int main(){

    const char *fifopath="/tmp/myfifo";
    int fifofd=open(fifopath,O_RDONLY);
    if(fifofd==-1){
        perror("failed to open fifo");
        return 1;
    }
    char buffer[1024];
    ssize_t bytesRead=read(fifofd,buffer,sizeof(buffer));
    close(fifofd);
    if(bytesRead>0){
        buffer[bytesRead]='\0';
        cout<<"Data read from fifo" << " "<< buffer<<endl;
    }
    else{
        cout<<"failed to read data from fifo"<<endl;
    }
    return 0;
}
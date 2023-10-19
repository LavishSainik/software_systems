/*
============================================================================
Name : 20a.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description :  Write two programs so that both can communicate by FIFO -Use one way communications. 
Date: 19th Oct, 2023.
============================================================================
*/

//writer program
#include<iostream>
#include<fcntl.h>
#include<stdio.h>
using namespace std;
#include<unistd.h>
#include<cstring>
#include<sys/stat.h>

int main(){

    const char *fifopath="/tmp/myfifo";
    mkfifo(fifopath,0666);//make if doesnt exist
    int fifofd=open(fifopath,O_WRONLY);
    if(fifofd==-1){
        perror("failed to open FIFO for writing");
        return 1;
    }
    //writing data to fifo
    const char *message ="Hello fifo";
    write(fifofd,message,strlen(message));
    close(fifofd);
    cout<<"data written to fifo "<<message<<endl;
    return 0;
}
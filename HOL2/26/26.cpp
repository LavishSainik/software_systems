/*
============================================================================
Name : 26.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to send messages to the message queue. Check $ipcs -q 
Date: 19th Oct, 2023.
============================================================================
*/
#include<iostream>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<cstring>
using namespace std;

struct Message{
    long mtype;
    char mtext[100];
}message;

int main(){
    key_t key =ftok(".",'A');
    if(key==-1){
        perror("Failed to generate a message queue key");
        return 1;
    }
    int msgQid=msgget(key,0666|IPC_CREAT);
    if(msgQid==-1){
        perror("Failed to get the message q id");
        return 1;
    }

    //prepare the msg
    message.mtype=1;
    string messageText="Hello,Good morning";
    strncpy(message.mtext,messageText.c_str(),sizeof(message.mtext));

    if(msgsnd(msgQid,&message,sizeof(message.mtext),0)==-1)
    {
        perror("msgsnd");
        return 1;
    }
    cout<<"Message sent to queue "<<messageText<<endl;

    //checking message status
    system("ipcs -q");

}

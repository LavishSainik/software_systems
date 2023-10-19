/*
============================================================================
Name : 25.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to print a message queue's  (use msqid_ds and ipc_perm structures)    a. access permission    b. uid, gid    c. time of last message sent and received       d. time of last change in the message queue    d. size of the queue    f. number of messages in the queue     g. maximum number of bytes allowed     h. pid of the msgsnd and msgrcv
Date: 19th Oct, 2023.
============================================================================
*/
#include<iostream>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<ctime>
#include<cstring>
using namespace std;
int main(){
    key_t key = ftok("/tmp",'A');

    if(key==-1){
        perror("Failed to generate a msg q");
        return 1;
    }
    int msgQid=msgget(key,0);
    if(msgQid==-1){
        perror("Failed to get the msg q id");
        return 1;
    }
    
    struct msqid_ds queueInfo;
    if(msgctl(msgQid,IPC_STAT,&queueInfo)==-1){
        perror("Failed to get message q info");
        return 1;
    }
    cout<<"Access permissions "<<queueInfo.msg_perm.mode<<endl;
    cout<<"UID"<<queueInfo.msg_perm.uid<<endl;
    cout<<"GID"<<queueInfo.msg_perm.gid<<endl;

    //convert timestamps to a redable format
    char timeBuffer[30];
    time_t lastSent = queueInfo.msg_stime;
    time_t  lastRecieved = queueInfo.msg_rtime;
    time_t lastChange = queueInfo.msg_ctime;

    strftime(timeBuffer,sizeof(timeBuffer),"%Y-%m-%d %H:%M:%S",localtime(&lastSent));
    cout << "c. Time of Last Message Sent: " << timeBuffer << endl;

       strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", localtime(&lastRecieved));
    cout << "   Time of Last Message Received: " << timeBuffer << endl;

    strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", localtime(&lastChange));
    cout << "d. Time of Last Change: " << timeBuffer << endl;

    cout<<"Size of Queue "<<queueInfo.msg_qbytes<<"bytes"<<endl;
    cout<<"Number of message in the Queue"<<queueInfo.msg_qnum<<endl;
    cout<<"maximum number of bytes allowed"<<queueInfo.msg_qbytes<<endl;
    cout<<"PID of msgsnd"<< queueInfo.msg_lspid<<endl;
    cout<<"PID of msgrcv"<<queueInfo.msg_lrpid<<endl;





return 0;}
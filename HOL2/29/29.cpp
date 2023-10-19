/*
============================================================================
Name : 29.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to remove the message queue
Date: 19th Oct, 2023.
============================================================================
*/
#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<cstdlib>
using namespace std;

int main(){
    int msgQid;
    key_t key=ftok(".",'A');
    msgQid=msgget(key,0666| IPC_CREAT);
    if(msgQid==-1){
        perror("msgget");
        return 1;
    }
    
    if(msgctl(msgQid,IPC_RMID,nullptr)==-1){
        perror("in removing");
        return 1;
    }
    cout<<"message q removed successfully"<<endl;




    return 0;
}
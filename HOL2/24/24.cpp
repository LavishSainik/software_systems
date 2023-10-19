/*
============================================================================
Name : 24.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to create a message queue and print the key and message queue id.
Date: 19th Oct, 2023.
============================================================================
*/
#include<iostream>
#include<sys/msg.h>
#include<cstdlib>
#include<stdio.h>
using namespace std;

int main(){

    //lets generate unique key for msg q
    //ftok fun used to generate a unique key for msg q
    //we can create a msg q using msgget with generated key
    key_t key =ftok("/tmp",'A');
    if(key==-1){
        perror("failed to generate a message queue key");
        return 1;
    }
    //lets create a message q
    int msgQid=msgget(key,IPC_CREAT|0666);
    if(msgQid==-1){
        perror("failed to create a message q");
        return 1;
    }
    cout<<"Message queue key "<<key<<endl;
    cout<<"Message queue id  "<<msgQid<<endl;
    return 0;
}
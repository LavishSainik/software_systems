/*
============================================================================
Name : 27a.c
Author : Yash Talele
Roll No. : MT2023186
Description : Write a program to receive messages from the message queue.    a. with 0 as a flag    b. with IPC_NOWAIT as a flag
Date: 6th Oct, 2023.
============================================================================
*/
#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<cstring>
#include<cstdlib>
using namespace std;

struct Message{
   long mtype;
   char mtext[255];

};

int main(){

    key_t key=ftok(".",'A');
    int msgQid;
    Message message;

    

    if((msgQid=msgget(key,0666))==-1){
        perror("msgget");
        return 1;
    }

   //recieve a msg with 0 as a flag
   if(msgrcv(msgQid,&message,sizeof(message.mtext),1,0)==-1){
        perror("msgrcv with 0 flag");
        return 1;
   }

   //recive msg with nowait

   if(msgrcv(msgQid,&message,sizeof(message.mtext),1,IPC_NOWAIT)==-1){
        perror("msgrcv with IPC_NOWAIT");

   }
   else
   {
      cout<<"Recieved msg wiith ipc nowait is "<< message.mtext<<endl;

   }





    return 0;
}
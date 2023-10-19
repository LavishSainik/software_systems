/*
============================================================================
Name : 28.cpp
Author : Lavish Saink
Roll No. : MT2023183
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 19th Oct, 2023.
============================================================================
*/
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Message
{
    long mtype;
    char mtext[255];
};

int main()
{

    int msgQid;    
    struct msqid_ds msgQinfo;

    key_t key =ftok(".",'A');
    
    if ((msgQid = msgget(key, 0666 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(1);
    }


    // Retrieving the current permissions and info of Q
    if (msgctl(msgQid, IPC_STAT, &msgQinfo) == -1)
    {
        perror("msgctl IPC_STAT");
        return 1;
    }

    // changing permissions
    msgQinfo.msg_perm.mode = 0644;

    // setting updated permissions
    if (msgctl(msgQid, IPC_SET, &msgQinfo) == -1)
    {
        perror("msgctl IPC_SET");
        return 1;
    }
    cout << "Message queue permission changed to 0644" << endl;

    return 0;
}
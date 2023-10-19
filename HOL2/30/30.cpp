/*
============================================================================
Name : 30a.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to create a shared memory.    
a. write some data to the shared memory    
b. attach with O_RDONLY and check whether you are able to overwrite.    
c. detach the shared memory    
d. remove the shared memory
Date: 19th Oct, 2023.
============================================================================
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;

int main(){
    
    key_t key;
    int shmid;
    char *sharedMemory;

    key=ftok(".",'B');
    //create shared mem segment with rw permissions
    shmid=shmget(key,1024,IPC_CREAT|0666);
    if(shmid==-1){
        perror("shmget");
        return 1;
    }

    //attach to shared memory segment
    sharedMemory = (char*)shmat(shmid,nullptr,0);
    
    //write data to shared mem
    strcpy(sharedMemory,"Hello,I am writing data in you");
    cout<<"Data written successfully "<<sharedMemory<<endl;
    
    //detach from shared mem segment
    if(shmdt(sharedMemory)==-1){
        perror("shmdt");
        return 1;
    }

    //attach to shared mem wiht rw permissions
    sharedMemory=(char*)shmat(shmid,nullptr,SHM_RDONLY);
    
    //try to overwrite the shared mem(should fail)
    // strcpy(sharedMemory,"Over-writing");

    //detach the shared mem again
    shmdt(sharedMemory);

    //removing shared mem segment
    shmctl(shmid,IPC_RMID,nullptr);

    cout<<"shared mem removed"<<endl;


    return 0;
}
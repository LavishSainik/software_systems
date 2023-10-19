/*
============================================================================
Name : 31.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to create a semaphore and initialize value to the semaphore.    
a. create a binary semaphore    b. create a counting semaphore
Date: 19th Oct, 2023.
============================================================================
*/
#include<iostream>
#include<cstdlib>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
using namespace std;

int main(){

    key_t key;
    int semIDbinary, semIDcounting;
    struct sembuf semOp;

    key=ftok(".",'C');
    semIDbinary = semget(key,1,IPC_CREAT| 0666);

    //initializing bin semaphore to 1(unlocked)
    semOp.sem_num=0;
    semOp.sem_op=1;
    semOp.sem_flg=0;
    int x=semop(semIDbinary,&semOp,1);
    if(x==-1){
        perror("semop");
        return 1;
    }
    cout<<"Binary semaphore created and initialized"<<endl;

    //creating counting semaphore with an initial val of 3
    
    semIDcounting = semget(key,1,IPC_CREAT|0666);
    if(semIDcounting==-1){
        perror("semget");
        return 1;
    }

    semOp.sem_num = 0;
    semOp.sem_op=3;
    semOp.sem_flg = 0;

    semop(semIDcounting,&semOp,1);
    cout<<"Counting semaphore created and initialized with 3"<<endl;


    return 0;





    return 0;
}
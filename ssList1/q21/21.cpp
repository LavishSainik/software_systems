/*
============================================================================
Name : 21.cpp
Author : Lavish Sainik
Description : program to call fork and print the parent and child process id.
Date: 8th sep , 2023.
============================================================================
*/

#include<iostream>
#include<unistd.h>
using namespace std;


int main(){
 
    pid_t child_pid;
    child_pid=fork();

    if(child_pid<0){
       cout<<"fork failed"<<endl;
    }
    else if(child_pid==0){
       cout<<"The child pid is "<< getpid()<<endl;
    }
    else{
       cout<<"The pid of process is  "<< getpid()<<endl;
       cout<<"The pid of child is  "<< child_pid<<endl;
    }



return 0;}

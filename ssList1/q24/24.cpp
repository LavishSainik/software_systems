/*
============================================================================
Name : 24.cpp
Author : Lavish Sainik
Description : Program to create an orphan process
Date: 8th sep, 2023.
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
	return 1;
    }
    else if(child_pid==0){
        cout<<"child pid is "<<getpid()<<endl;
	sleep(100);
    }
    else{
        cout<<"parent pid is "<<getpid()<<endl;
    }



return 0;}

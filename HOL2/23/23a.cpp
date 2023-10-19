/*
============================================================================
Name : 23.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to print the maximum number of files can be opened within a process and  
size of a pipe (circular buffer). 
Date: 19th Oct, 2023.
============================================================================
*/
#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<sys/resource.h>
using namespace std;

int main(){
    
    struct rlimit fileLimit;
    if(getrlimit(RLIMIT_NOFILE,&fileLimit)==0){
        cout<<"Maximum number of files that can be opened(soft limit)"<<fileLimit.rlim_cur<<endl;
        cout<<"maximum no. of files that can be open(hard limit)"<<fileLimit.rlim_max<<endl;

    }
    else{
        perror("failed to get the file limit");
    }
    
    

    return 0;
}
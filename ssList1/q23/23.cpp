/*
============================================================================
Name : 23.cpp
Author : Lavish Sainik
Description : Program to create a zombie state of a running program
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
     return 1;
     exit(0);
  }
  else{
     cout<<"parent pid is "<<getpid()<<endl;
     sleep(10);
  }



return 0;}

/*
============================================================================
Name : 27c.cpp
Author : Lavish Sainik
Description : Program to executr ls -Rl by the execle system call.
Date: 8th sep, 2023.
============================================================================
*/

#include<iostream>
#include<unistd.h>
using namespace std;

int main(){

  if(execlp("ls","ls","-Rl",nullptr)==-1){
      perror("execlp");
      return 1;
  }

return 0;}

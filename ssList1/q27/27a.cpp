/*
============================================================================
Name : 27a.cpp
Author : Lavish Sainik
Description : Program to executr ls -Rl by the execl system call.
Date: 8th sep, 2023.
============================================================================
*/


#include<iostream>
#include<unistd.h>
#include<cstdlib>
using namespace std;


int main(){

  if(execl("/bin/ls","ls","-Rl",nullptr)==-1){
      perror("execl");
      return 1;
  }


return 0;}

/*
============================================================================
Name : 27d.cpp
Author : Lavish Sainik
Description : Program to executr ls -Rl by the execv system call.
Date: 8th sep, 2023.
============================================================================
*/

#include<iostream>
#include<unistd.h>
#include<cstdlib>
using namespace std;


int main(){

  char* args[]= {(char*)"/bin/ls", (char*)"ls", (char*)"-Rl",nullptr};
  if(execv("/bin/ls",args)==-1){
      perror("execv");
      return 1;
  }

return 0;}

/*
============================================================================
Name : 27a.cpp
Author : Lavish Sainik
Description : Program to execute ls -Rl by the execlp system call.
Date: 8th sep, 2023.
============================================================================
*/


#include<iostream>
#include<unistd.h>
#include<cstdlib>
using namespace std;


int main(){

   char* envp={nullptr};
   if(execle("/bin/ls","ls","-Rl",nullptr,envp)==-1){
       perror("execle");
       return 1;
   }


return 0;}

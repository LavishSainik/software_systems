/*
============================================================================
Name : 20.cpp
Author : Lavish Sainik
Description : Program to find out priority of running process and modify it by nice command.
Date: 8th sep, 2023.
============================================================================
*/


#include<iostream>
#include<unistd.h>
using namespace std;
#include<cstdlib>
#include<sys/resource.h>
#include<sys/time.h>

int main(){
 
   int niceness = 10;
   cout<<"Original priority "<<getpriority(PRIO_PROCESS,0)<<endl;

   if(nice(niceness)==-1){
       perror("nice error");
       return 1;
   }

   cout<<"New priority "<< getpriority(PRIO_PROCESS,0)<<endl;



return 0;
}

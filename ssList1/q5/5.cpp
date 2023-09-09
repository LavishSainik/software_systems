/*
============================================================================
Name : 5.c
Author : Lavish Sainik
Description : program to create 5 new files using infinite loop.
Date: 28th Aug, 2023.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdbool.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
   int k=0;
   FILE* file;
  
   while(1){
      char buffer[32];
      if(k<5){
         k++;
	 printf(buffer,sizeof(char)*32,"file%i.txt",k);
         file = fopen(buffer,"wb");
	 fclose(file);
      }
   }
 


return 0;}

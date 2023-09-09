/*
============================================================================
Name : 15.cpp
Author : Lavish Sainik
Description : program to display the environment variable of user
Date: 28th Aug, 2023.
============================================================================
*/

#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<cstdlib>
using namespace std;

extern char** environ; 

int main(){

    for(char** env = environ; *env!=NULL; ++env){
          cout<<*env<<endl;
    }


return 0;}

/*
============================================================================
Name : 8.cpp
Author : Lavish Sainik
Description : program to open a file , read line by line and display each line as it is read, close the file when EOF reached.
Date: 7th sep, 2023.
============================================================================
*/

#include<iostream>
#include<fstream>
using namespace std;
#include<string>
int main(){

   fstream ffile;
   ffile.open("rdd");

   if(ffile.is_open()){
     string ss;

     while(getline(ffile,ss)){
        cout<<ss<<endl;
     }
     ffile.close();
   
   }


return 0;}


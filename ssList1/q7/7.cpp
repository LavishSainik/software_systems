/*
============================================================================
Name : 7.cpp
Author : Lavish Sainik
Description : program to copy file1 to file2.
Date: 7th sep, 2023.
============================================================================
*/

#include<iostream>
using namespace std;
#include<fstream>

int main(){

    ifstream sourcefile("sample1");
    ofstream destination("sample2");

    destination << sourcefile.rdbuf();
    sourcefile.close();
    destination.close();


return 0;}

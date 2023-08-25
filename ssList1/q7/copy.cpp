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

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


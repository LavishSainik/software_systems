#include<iostream>
using namespace std;
#include<unistd.h>
#include<fcntl.h>

int main(){

   int fd;
   fd=open("mode.cpp",O_RDONLY);
   int flags = fcntl(fd, F_GETFL);
   cout<<flags<<endl;
       if(flags==32768){
       cout<<"the file is open in read only mode"<<endl;
       }
       else  if(flags==32769){
         cout<<"file is open in read in write mode"<<endl;
       }
      
    close(fd);

return 0;}

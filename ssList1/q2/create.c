#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
   
   int fd;
   fd=creat("x.text",O_CREAT);
   printf("%d",fd);

 
   return 0;}

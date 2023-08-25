#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
   
   int fd;
   fd=open("/home/lavish2509/ssList1/q3/toopen.text",O_RDWR);
   printf("%d",fd);


   return 0;}

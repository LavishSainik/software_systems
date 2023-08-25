#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdbool.h>
#include<bits/stdc++.h>
using namespace std;
int main(){

   int fd;
   int i=0;
   string s="";
   while(true){
	   s=to_string(i)+".txt";
	   char hh[s.length()+1];
	   strcpy(hh,s.c_str());
      printf("press ctrl+c to stop\n");
      fd=creat(hh,S_IRWXU);
      printf("%d",fd);
      i++;
   }

 


return 0;}

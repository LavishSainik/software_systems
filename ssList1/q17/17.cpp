/*
============================================================================
Name : 17.cpp
Author : Lavish sainik
Description : a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 8th sep, 2023.
============================================================================
*/


#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<fstream>
using namespace std;
   
          const char* path = "/home/lavish2509/handson1/q17/reserve.txt";


int main(){

	int fd = open(path,O_RDWR);
	if(fd==-1){
	  perror("opening file");
	  return 1;
	}
	struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_start =0;
	lock.l_whence=SEEK_SET;
	lock.l_len=0;
	if (fcntl(fd,F_SETLKW,&lock)==-1){
	   perror("acquiring write lock");
	   return 1;
	}

	int current_ticket=0;
        if(read(fd,&current_ticket,sizeof(current_ticket))==-1){
	    perror("REading current ticket no.");
	    return 0;
	}
	int new_ticket = current_ticket+1;

	//writing new ticket number to file
	
	if(lseek(fd,0,SEEK_SET)==-1){
	   perror("seeking to the beginning of file");
	   close(fd);
	   return 1;
	}

	if(write(fd,&new_ticket,sizeof(new_ticket))==-1){
	   perror("writing new ticket to fuke");
	   close(fd);
	   return 1;
	}

	lock.l_type=F_UNLCK;
	if(fcntl(fd,F_SETLKW,&lock)==-1){
	  perror("releasing write lock");
	  return 1;
	}
	close(fd);
	cout<<"ticket reserved  "<<new_ticket<<endl;



return 0;}

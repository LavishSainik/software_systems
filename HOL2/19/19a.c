/*
============================================================================
Name : 19a.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description :  Create a FIFO file by    a. mknod command    b. mkfifo command    c. use strace command to find out, which command (mknod or mkfifo) is better.    c. mknod system call    d. mkfifo library function
Date: 19th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
        execlp("mknod","mknod","fifo2","p",NULL);

        return 0;
}

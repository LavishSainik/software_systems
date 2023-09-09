/*
============================================================================
Name : 1a.c
Author : Lavish Sainik
Description : Create the following types of a files using 
              (i) shell command (ii) system call
              a. soft link (symlink system call)
              b. hard link (link system call)
Date: 19 August, 2023
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int sym_link(const char* f1, const char* f2) {
  return symlink(f1, f2);
}

int hard_link(const char* f1, const char* f2) {
  return link(f1, f2);
}

void main() {
  const char* f1="original.txt";
  const char* f2="symlink-shell.txt";
  printf("Softlink = %d\n", sym_link(f1, f2));
  const char* f3="hardlink-shell.txt";
  printf("Hardlink = %d\n", hard_link(f1, f3));
}

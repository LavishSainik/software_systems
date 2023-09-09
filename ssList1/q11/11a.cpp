/*
============================================================================
Name : 11a.cpp
Author : Lavish Sainik
Description : a program to open a file,duplicate the fd using dup system call.
Date: 8th sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int file_descriptor, new_descriptor;
    char filename[] = "example.txt";

    // Open the file
    file_descriptor = open(filename, O_WRONLY | O_APPEND);

    if (file_descriptor == -1) {
        perror("Error opening file");
        return 1;
    }

    // Duplicate the file descriptor
    new_descriptor = dup(file_descriptor);

    // Write to the original descriptor
    write(file_descriptor, "Original Descriptor\n", 20);

    // Write to the duplicated descriptor
    write(new_descriptor, "Duplicated Descriptor\n", 21);

    // Close both descriptors
    close(file_descriptor);
    close(new_descriptor);

    return 0;
}




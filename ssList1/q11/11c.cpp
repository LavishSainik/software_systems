/*
============================================================================
Name : 11c.cpp
Author : Lavish Sainik
Description : A program to copy the fd using fcntl.
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

    // Duplicate the file descriptor using fcntl
    new_descriptor = fcntl(file_descriptor, F_DUPFD, 0);

    // Write to the original descriptor
    write(file_descriptor, "Original Descriptor\n", 20);

    // Write to the duplicated descriptor
    write(new_descriptor, "Duplicated Descriptor\n", 21);

    // Close both descriptors
    close(file_descriptor);
    close(new_descriptor);

    return 0;
}


/*
============================================================================
Name : 11b.cpp
Author : Lavish sainik
Description : A program to open a file, duplicate the fd using dup2 and append the file fd.
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

    // Duplicate the file descriptor using dup2
    new_descriptor = dup2(file_descriptor, 3);  // Use an available file descriptor, e.g., 3

    // Write to the original descriptor
    write(file_descriptor, "Original Descriptor\n", 20);

    // Write to the duplicated descriptor
    write(new_descriptor, "Duplicated Descriptor\n", 21);

    // Close both descriptors
    close(file_descriptor);
    close(new_descriptor);

    return 0;
}


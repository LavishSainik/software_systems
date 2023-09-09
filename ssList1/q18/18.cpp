/*
============================================================================
Name : 18.c
Author : Boppana Venkatesh
Description : Write a C, Ansi-style program to perform Record locking.
Date: 8th sep, 2023.
============================================================================
*/

#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

#define RECORD_SIZE 100

void printRecord(const char* record) {
    std::cout << "Record: " << record << std::endl;
}

void writeRecord(int fd, int recordNumber, const char* data) {
    off_t offset = static_cast<off_t>(recordNumber) * RECORD_SIZE;
    lseek(fd, offset, SEEK_SET);
    write(fd, data, strlen(data));
}

void readRecord(int fd, int recordNumber, char* buffer) {
    off_t offset = static_cast<off_t>(recordNumber) * RECORD_SIZE;
    lseek(fd, offset, SEEK_SET);
    read(fd, buffer, RECORD_SIZE);
}

int main() {
    const char* filename = "record_file.txt";
    const char* records[] = { "Record 1", "Record 2", "Record 3" };

    // Create and open the file for read/write
    int fd = open(filename, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    for (int i = 0; i < 3; ++i) {
        // Attempt to obtain a write lock on the record
        struct flock lock;
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = static_cast<off_t>(i) * RECORD_SIZE;
        lock.l_len = RECORD_SIZE;
        
        if (fcntl(fd, F_SETLKW, &lock) == -1) {
            std::cerr << "Failed to obtain a write lock on Record " << (i + 1) << std::endl;
            close(fd);
            return 1;
        }

        // Read and print the record
        char buffer[RECORD_SIZE];
        readRecord(fd, i, buffer);
        printRecord(buffer);

        // Simulate a modification
        // In a real application, you can perform your data updates here.
        // For simplicity, we just append " (Modified)" to the record.
        strcat(buffer, " (Modified)");
        writeRecord(fd, i, buffer);

        // Release the write lock
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
    }

    close(fd);

    return 0;
}


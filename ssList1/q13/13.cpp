/*
============================================================================
Name : 13.cpp
Author : Lavish Sainik
Description : a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not
Date: 28th Aug, 2023.
============================================================================
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    fd_set readfds;
    struct timeval timeout;

    // Clear the set and add STDIN (file descriptor 0) to it
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);

    // Set the timeout to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    std::cout << "Waiting for input on STDIN for 10 seconds..." << std::endl;

    // Use select to wait for input on STDIN
    int result = select(1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select");
        return 1;
    } else if (result == 0) {
        std::cout << "No data available within 10 seconds." << std::endl;
    } else {
        if (FD_ISSET(0, &readfds)) {
            std::cout << "Data is available on STDIN!" << std::endl;
            // You can read the data from STDIN here if needed
        } else {
            std::cerr << "Unexpected error." << std::endl;
            return 1;
        }
    }

    return 0;
}




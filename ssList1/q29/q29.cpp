/*
============================================================================
Name : 29.cpp
Author : Lavish Sainik
Description : Program to get scheduling policy and modify the scheduling policy
Date: 8th sep, 2023.
============================================================================
*/
#include <iostream>
#include <sched.h>
#include <cstdlib>
#include <cstring>
#include<unistd.h>
int main() {
    int pid = getpid(); 
    int current_policy = sched_getscheduler(pid);
    if (current_policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

  
    std::cout << "Current scheduling policy for PID " << pid << ": ";
    switch (current_policy) {
        case SCHED_FIFO:
            std::cout << "SCHED_FIFO" << std::endl;
            break;
        case SCHED_RR:
            std::cout << "SCHED_RR" << std::endl;
            break;
        case SCHED_OTHER:
            std::cout << "SCHED_OTHER" << std::endl;
            break;
        default:
            std::cout << "Unknown" << std::endl;
    }

    // Set the new scheduling policy (e.g., SCHED_FIFO)
    struct sched_param param;
    param.sched_priority = 99; // Set the priority for SCHED_FIFO (1-99)
    int new_policy = SCHED_FIFO;

    int result = sched_setscheduler(pid, new_policy, &param);
    if (result == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    
    current_policy = sched_getscheduler(pid);
    if (current_policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    std::cout << "Updated scheduling policy for PID " << pid << ": ";
    switch (current_policy) {
        case SCHED_FIFO:
            std::cout << "SCHED_FIFO" << std::endl;
            break;
        case SCHED_RR:
            std::cout << "SCHED_RR" << std::endl;
            break;
        case SCHED_OTHER:
            std::cout << "SCHED_OTHER" << std::endl;
            break;
        default:
            std::cout << "Unknown" << std::endl;
    }

    return 0;
}


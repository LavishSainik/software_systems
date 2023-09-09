/*
============================================================================
Name : 28.cpp
Author : Lavish Sainik
Description : A program to get maximum and minimum real time priority
Date: 8th sep, 2023.
============================================================================
*/

#include <iostream>
#include <sched.h>

int main() {
    int policy;
    int max_priority, min_priority;

    // Get the maximum real-time priority for the SCHED_FIFO scheduling policy
    policy = SCHED_FIFO;
    max_priority = sched_get_priority_max(policy);
    min_priority = sched_get_priority_min(policy);

    std::cout << "Maximum real-time priority for SCHED_FIFO: " << max_priority << std::endl;
    std::cout << "Minimum real-time priority for SCHED_FIFO: " << min_priority << std::endl;

    // Get the maximum real-time priority for the SCHED_RR scheduling policy
    policy = SCHED_RR;
    max_priority = sched_get_priority_max(policy);
    min_priority = sched_get_priority_min(policy);

    std::cout << "Maximum real-time priority for SCHED_RR: " << max_priority << std::endl;
    std::cout << "Minimum real-time priority for SCHED_RR: " << min_priority << std::endl;

    return 0;
}


/*
============================================================================
Name : 32b.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to implement semaphore to protect any critical section.    
            a. rewrite the ticket number creation program using semaphore    
            b. protect shared memory from concurrent write access    
            c. protect multiple pseudo resources ( may be two) using counting semaphore    
            d. remove the created semaphore  
Date: 19th Oct, 2023.
============================================================================
*/
#include <iostream>
#include <thread>
#include <semaphore.h>

int sharedData = 0;
sem_t semaphore;

void writeToSharedMemory(int data) {
    sem_wait(&semaphore); // Wait for the semaphore
    sharedData = data;
    std::cout << "Thread " << std::this_thread::get_id() << " wrote data: " << data << std::endl;
    sem_post(&semaphore); // Release the semaphore
}

int main() {
    sem_init(&semaphore, 0, 1); // Initialize the semaphore with an initial value of 1
    std::thread t1(writeToSharedMemory, 42);
    std::thread t2(writeToSharedMemory, 99);
    t1.join();
    t2.join();
    sem_destroy(&semaphore); // Destroy the semaphore
    return 0;
}

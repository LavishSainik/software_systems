/*
============================================================================
Name : 32d.cpp
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
#include <semaphore.h>

int main() {
    sem_t semaphore;
    sem_init(&semaphore, 0, 1); // Initialize the semaphore with an initial value of 1

    // Your code using the semaphore here...

    // When you're done using the semaphore, destroy it:
    sem_destroy(&semaphore);

    return 0;
}

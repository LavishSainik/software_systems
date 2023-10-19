/*
============================================================================
Name : 32a.cpp
Author : Lavish Sainik
Roll No. : MT2023183
Description : Write a program to implement semaphore to protect any critical section.    a. rewrite the ticket number creation program using semaphore    b. protect shared memory from concurrent write access    c. protect multiple pseudo resources ( may be two) using counting semaphore    d. remove the created semaphore  
Date: 19th Oct, 2023.
============================================================================
*/
#include <iostream>
#include <thread>
#include <semaphore.h>

const int NUM_TICKETS = 100;
int ticketCounter = 0;
sem_t semaphore;

void sellTicket() {
    for (int i = 0; i < NUM_TICKETS; i++) {
        sem_wait(&semaphore); // Wait for the semaphore
        ticketCounter++;
        std::cout << "Ticket " << ticketCounter << " sold by Thread " << std::this_thread::get_id() << std::endl;
        sem_post(&semaphore); // Release the semaphore
    }
}

int main() {
    sem_init(&semaphore, 0, 1); // Initialize the semaphore with an initial value of 1
    std::thread t1(sellTicket);
    std::thread t2(sellTicket);
    t1.join();
    t2.join();
    sem_destroy(&semaphore); // Destroy the semaphore
    return 0;
}

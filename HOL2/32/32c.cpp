/*
============================================================================
Name : 32c.cpp
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

const int NUM_RESOURCES = 2;
int resourceCounter[NUM_RESOURCES] = {0, 0};
sem_t semaphores[NUM_RESOURCES];

void useResource(int resourceID) {
    sem_wait(&semaphores[resourceID]); // Wait for the semaphore
    resourceCounter[resourceID]++;
    std::cout << "Thread " << std::this_thread::get_id() << " is using resource " << resourceID << std::endl;
    // Simulate resource usage
    std::this_thread::sleep_for(std::chrono::seconds(1));
    resourceCounter[resourceID]--;
    sem_post(&semaphores[resourceID]); // Release the semaphore
}

int main() {
    for (int i = 0; i < NUM_RESOURCES; i++) {
        sem_init(&semaphores[i], 0, 1); // Initialize each semaphore with an initial value of 1
    }

    std::thread t1(useResource, 0);
    std::thread t2(useResource, 1);
    t1.join();
    t2.join();

    for (int i = 0; i < NUM_RESOURCES; i++) {
        sem_destroy(&semaphores[i]); // Destroy each semaphore
    }

    return 0;
}

/*
============================================================================
Name : 30.cpp
Author : Lavish Sainik
Description : program to run a script at a specific time using a Daemon process.
Date: 8th sep, 2023.
============================================================================
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void runScript() {
    // Replace this with the actual command to run your script
    system("/path/to/your/script.sh");
}

int main() {
    // Fork the parent process
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Failed to fork the process." << std::endl;
        return 1;
    }

    if (pid > 0) {
        // Parent process
        std::cout << "Daemon process started with PID: " << pid << std::endl;
        return 0;
    }


    if (chdir("/") < 0) {
        std::cerr << "Failed to change the working directory." << std::endl;
        return 1;
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // Run the script at a specific time
    // For example, runScript() is called at midnight (00:00)
    struct tm targetTime;
    targetTime.tm_hour = 0;  
    targetTime.tm_min = 0;   
    targetTime.tm_sec = 0;   

    time_t now;
    struct tm* current;
    time(&now);
    current = localtime(&now);

    int secondsUntilRun = difftime(mktime(&targetTime), mktime(current));

    if (secondsUntilRun < 0) {
        secondsUntilRun += 86400;  // Add 24 hours in seconds
    }

    std::cout << "Daemon will run the script in " << secondsUntilRun << " seconds." << std::endl;

    sleep(secondsUntilRun);  
    runScript();

    return 0;
}


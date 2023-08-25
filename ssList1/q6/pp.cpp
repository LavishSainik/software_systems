#include<iostream>
#include<unistd.h>
#include<fcntl.h>

int main(){

   #include <iostream>
#include <unistd.h>

int main() {
    const int bufferSize = 1024;
    char buffer[bufferSize];
    
    ssize_t bytesRead;
    while ((bytesRead = read(STDIN_FILENO, buffer, bufferSize)) > 0) {
        ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
        if (bytesWritten == -1) {
            perror("write");
            return 1;
        }
    }
    
    if (bytesRead == -1) {
        perror("read");
        return 1;
    }
    
    return 0;
}
  }



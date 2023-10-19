//for the size of  pipe's circular buffer

#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;
int main(){
    
    int pipefd[2];
    int x =pipe(pipefd);
    if(x==-1){
        perror("Failed to create a pipe");
        return 1;
    }
    //Setting the write end of the pipe to non-blocking mode is necessary in this context to avoid getting stuck in an infinite loop when the pipe's circular buffer is full.
    //By default, when you write to a pipe and its buffer is full, the write call will block until space is available in the buffer. In a non-blocking mode, if the buffer is full and the write call would block, it returns immediately with an error (EAGAIN or EWOULDBLOCK) instead of blocking the program.
     int flags = fcntl(pipefd[1], F_GETFL);
    fcntl(pipefd[1], F_SETFL, flags | O_NONBLOCK);
    char buffer[4096];
    int bytesWritten=0;

    while(true){
        int result = write(pipefd[1],buffer,sizeof(buffer));
        if(result==-1){
           if(errno==EAGAIN){
            break;
           }
        }
        bytesWritten += result;
    }
    close(pipefd[0]);
    close(pipefd[1]);

    cout<<bytesWritten<<"bytes"<<endl;



    return 0;
}
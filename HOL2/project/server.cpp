#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#define SERVER_PORT 8888;
#define MAX_CONNECTIONS 100;
using namespace std;
enum user_type{ADMIN,STUDENT,FACULTY};

typedef struct{
    int id;
    enum user_type type;
    char username[128];
    char password[128];
}user_t;

typedef struct{
    int socket_fd;
    user_t user;
}client_connection_t;

typedef struct{
    int id;
    char name[128];
    int credits;
    char instructor[128];
}course_t;

pthread_mutex_t user_db_mutex;

//user database
user_t user_db[100];

//defines course database
course_t course_db[100];

//load user db from file

void load_user_db(){
    int fd = open("/home/lavish2509/list2/project/users.db",O_RDONLY);
    if(fd<0){
        perror("open");
        exit(1);
    }


//reading user from file and add it to db
char buff[1024];
while(1){
    int bytes_read = read(fd,buff,sizeof(buf));
    if(bytes_read<0){
        perror("read");
        break;
    }
    if(bytes_read==0){
        break;
    }
    user_t user ;
    sscanf(buff, "%d %d %s %s\n", &user.id, &user.type, user.username, user.password);
    user_db[user.id]=user;
}
close(fd);
}


void save_user_db(){
    int fd=open("/home/lavish2509/list2/project/users.db",O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(fd==-1){
        perror("open");
        exit(1);
    }
    char buf[1024];
    for(int i=0;i<100;i++){
        user_t user = user_db[i];
        if(user.username[0]!='\0'){
            sprintf(buf,"%d %d %s %s\n",user.id,user.type,user.username,user.password);
            int bytes_written = write(fd,buf,strlen(buf));
            if(bytes_written==-1){
                perror("write");
                break;
            }
        }
    }
    close(fd);
}

//authenticate user

int authenticate_user(char *username,char *password){
    //Lock the  user database mutex
    pthread_mutex_lock(&user_db_mutex);
    //search for the user in database
    int i,id;
    for(int i=0;i<100;i++){
        user_t user =user_db[i];
        if(strcmp(user.username,username)==0 && strcmp(user.password,password)==0)
        {
            id=user.id;
            break;
        }   
    }
    //Unlock the db mutex
    pthread_mutex_unlock(&user_db_mutex);
    //if the user was found return their id otherwise return -1
    return(i<100) ? id :-1;
}

int create_user(char *username,char *password,enum user_type type){
    //lock the user database mutex
    pthread_mutex_lock(&user_db_mutex);
    //find the next avaliable user id
    int id=0;

    while(user_db[id].username[0]!='\0'){
        id++;
    }
    //create a new user
    user_t user;
    user.id=id;
    user.type=type;
    strncpy(user.username,username,strlen(username));
    strncpy(user.password,password,strlen(password));
    user_db[id]=user;
    cout<<user.username<<user.password<<endl;

    //unclock the user database mutex
    pthread_mutex_unlock(&user_db_mutex);
    //return the new user id
    cout<<id;
    return id;
}

void *handle_client_connection(void *args){
    //Get the client connection info
    client_connection_t *client_connection = (client_connection_t *)args;

    char choice[1];
    if(recv(client_connection->socket_fd,choice,sizeof(choice),0)<0){
        perror("recv");
    }
    int ch = atoi(choice);
    client_connection->user.type=ch-1;
    
}
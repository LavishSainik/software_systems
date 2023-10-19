#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<errno.h>
#include<string.h>
#include<sys/wait.h>
#include<termios.h>
#define SERVER_PORT 8888
using namespace std;


int main(){
  
  struct termios old_settings,new_settings;
  tcgetattr(STDIN_FILENO,&old_settings);
  char username[100];
  char password[100];
  
  //creating a socket
  int client_socket = socket(AF_INET,SOCK_STREAM,0);
  if(client_socket==-1){
    perror("IN creating socket");
    exit(EXIT_FAILURE);
  }

  //connecting to server
  struct sockaddr_in server_address;

  server_address.sin_family=AF_INET;
  server_address.sin_port=htons(SERVER_PORT);
  server_address.sin_addr.s_addr=INADDR_ANY;

  int connect_result=connect(client_socket,(struct sockaddr *)&server_address,sizeof(server_address));

  if(connect_result==-1){
    perror("connect");
    exit(EXIT_FAILURE);
  }

  char message[1024];
  int recv_result = recv(client_socket,message,sizeof(message),0);
  if(recv_result<0){
    perror("recv");
    exit(EXIT_FAILURE);
  }

  cout<<message<<endl;

  char choice[1];
  char* main_menu = "WELCOME TO ACADEMIA\n"
                    "1.Admin\n"
                    "2.Faculty\n"
                    "3.Student\n"
                    "Enter the choice : ";
  cout<<"MAIN MENU"<<endl;
  cin>>choice;

  if(send(client_socket,choice,sizeof(choice),0)==-1){
     perror("send");
     exit(EXIT_FAILURE);
  }
  cout<<"Enter your username"<<endl;
  cin>>username;

  if(send(client_socket,username,sizeof(username),0)==-1){
      perror("send");
      exit(EXIT_FAILURE);
  }

  new_settings=old_settings;
  new_settings.c_lflag &=~ECHO;
  
  tcsetattr(STDIN_FILENO,TCSANOW,&new_settings);
  cout<<"Enter new password  "<<endl;
  cin>>password;
  tcsetattr(STDIN_FILENO,TCSANOW,&old_settings);
  
  if(send(client_socket,password,sizeof(password),0)<0){
    perror("send");
    exit(EXIT_FAILURE);
  }
  cout<<password<<endl;

  char msg[1024];
  if(recv(client_socket,msg,sizeof(msg),0)<0){
    perror("recv");
    exit(EXIT_FAILURE);
  }
  cout<<msg<<endl;
  close(client_socket);










  
  return 0;
     
}
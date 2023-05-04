//Muhammad farid 194308
//Anas ahmed 205270
//Abdelrahman 188065


#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#define MAX 80 
#define PORT 8080
#define SA struct sockaddr 
void func(int sockfd) 
{ 
    char buff[MAX]; 
    int postCode;
    int n; 
    int yn;
    for (;;) { 
    	postCode=0;
    	yn=0;
        
         
        printf("\nEnter postcode: "); 
        scanf("%d", &postCode);
        send(sockfd, &postCode, sizeof(postCode),0); 
        
        bzero(buff, sizeof(buff)); 
        
        read(sockfd, buff, sizeof(buff)); 
        printf("Avalible hospitals : %s \n", buff);
        
        
        printf("Need specilizations? \t");
        scanf("%d", &yn);
        send(sockfd, &yn, sizeof(yn),0); 
        bzero(buff, sizeof(buff)); 
        read(sockfd, buff, sizeof(buff)); 
        printf("Avalivle specilization : %s\n", buff);
        bzero(buff,MAX); 
        read(sockfd, buff,sizeof(buff));
        printf("%s\n", buff);
        
        
        
    } 
} 
  
int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
  
    // function for chat 
   func(sockfd); 
  
    // close the socket 
    close(sockfd); 
} 

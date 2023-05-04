//Muhammad farid 194308
//Anas ahmed 205270
//Abdelrahman 188065

#include <string.h>
#include <unistd.h>
#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
char* p1 = "\n H1.Enfolding Arms\n H2.24hr Homecare\n";
char* p2 = "\n H1.new path health\n H2.Silver Crest Hospital\n 3.Wake and Wonder";
char* p3 = "\n H1.Life flash Clinic\n";
char* p4 = "\n H1.Rey Az Mir Health\n H2.Academy Health Plaza\n";
char* H1 = "\nH1:cardio\nH2:internal\n";
char* H2 = "\nH1:ortho,kids\nH2:eyes,surgery\nH3:surgery,kids\n";
char* H3 = "\nH1:children\nH2:internal,eyes\n";
char* H4 = "\nH1:eye\nH2:surgery\n";
char* H5 = "\nH1:children\nH2:ortho,surgery\n";
char* H6 = "\nH1:children,eyes\nH2:surgery\nH3:eyes\nH4:ortho,eyes\n";
char* extra="info is sent to the nearest hospital you got on location they will be wating\n";
  
// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
for(;;){
     char buff[MAX]; 
        int n; 
        int postCode;
        int yn;
    
    
    	
        bzero(buff, sizeof(buff)); 
        n = 0; 
      read(sockfd,&postCode,sizeof(postCode));
      printf("from client: %d\n ", postCode);
      //select area
      if(postCode<=4){
      switch(postCode){
      
      case 1:
      write(sockfd,p1,sizeof(buff));
      break;
      case 2:
      write(sockfd,p2,sizeof(buff));
      break;
      case 3:
      write(sockfd,p3,sizeof(buff));
      break;
      case 4:
      write(sockfd,p4,sizeof(buff));
      break;
      
      
      }
      
      read(sockfd,&yn,sizeof(yn));
      printf("\nclient response %d\n",yn);
      bzero(buff,MAX);
      n=0;
        //show names
      if ( yn == 1  && postCode == 1 ) {
        write(sockfd,H1,sizeof(buff));
        write(sockfd,extra,sizeof(buff));
  }
        else if( yn == 1  && postCode == 2)
  {

        write(sockfd,H2,sizeof(buff));
        write(sockfd,extra,sizeof(buff));
  }
        else if ( yn == 1  && postCode == 3 ) {
        write(sockfd,H3,sizeof(buff));
        write(sockfd,extra,sizeof(buff));
      
  }
        else if ( yn == 1  && postCode == 4 ) {
        write(sockfd,H4,sizeof(buff));
        write(sockfd,extra,sizeof(buff)); 
  }

 }
 
  }
}
// Driver function 
int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
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
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 

    // Function for chatting between client and server 
    func(connfd); 
  
    // After chatting close the socket 
    close(sockfd); 
} 


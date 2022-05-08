/* A simple server in the internet domain using TCP
   The port number is passed as an argument */


#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char client_message[2000]; // buffer to store client message
char buffer[1024]; // buffer to store data
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // mutex for critical section

void *socketThread(void *arg)
{
    int newsockfd = *(int *)arg;

    /* UNIMPLEMENTED: TO DO */
    /* read a message from the client and store it in client_message */
    /* Use pthread_mutex_lock and pthread_mutex_unlock to lock and unlock the critical section */
    /* send the message "Read from Client: {client_message}" (stored in buffer) back to the client */
    /* close the socket */

}
void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno, clilen;
    //  char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }

     /* create socket */

     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");

     /* fill in port number to listen on. IP address can be anything (INADDR_ANY) */

     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);

     /* bind socket to this port number on this machine */

     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     
     /* listen for incoming connection requests */

    if(listen(sockfd,50)==0)printf("Listening\n");
    else printf("Error\n");

    pthread_t tid[51];
    int i =0;

    while(1)
    {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) error("ERROR on accept");

        /* TO DO: Create a thread for each client */
        /* TO DO: Each Thread starts executing function socketThread */
        /* TO DO: Each Thread should pass the socket descriptor as an argument */
       
        
        /* TO DO: Join the threads if 50 threads are created and running */
       
    }

}
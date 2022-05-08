#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

struct host_port
{
    char* hostname;
    int port;
};
void error(char *msg)
{
    perror(msg);
    exit(0);
}

void *clientThread(void* server_hostport)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    struct host_port* hostport = (host_port*)server_hostport;

    char *hostname = hostport->hostname;
    portno = hostport->port;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)error("ERROR opening socket");

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);


    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) error("ERROR connecting");

    strcpy(buffer,"Hello");

    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) 
        error("ERROR writing to socket");
    bzero(buffer, 256);


    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);

}


int main(int argc, char *argv[])
{
    /* Creating a thread for each client */
    /* At a time atmost 50 threads can be working concurrently, your code must incorporate that */
    /* Sleep for 20 seconds after generating 50 threads and then join the threads */

    int i = 0;
    pthread_t tid[51];
    while(i< 50)
    {
        struct host_port hostport;
        hostport.hostname = "localhost";
        hostport.port = atoi(argv[2]);
        if( pthread_create(&tid[i++], NULL, clientThread, &hostport) != 0 )
            printf("Failed to create thread\n");
    }

    sleep(20);
    i=0;

    while(i< 50)
    {
        pthread_join(tid[i++], NULL);
    }   

    return 0;
}

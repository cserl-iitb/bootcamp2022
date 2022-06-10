/* run using ./server <port> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <netinet/in.h>

#include <pthread.h>

// error handling function
void error(char *msg) {
  perror(msg);
  exit(1);
}

// non-CPU intensive server pause
void IO(float sec) { usleep((int)(sec * 1e6)); }

// CPU intensive server pause
void CPU(int n) {
  for (int i = 0; i < n; i++) {
    int x = i * i;
  }
}

// mix of CPU and non-CPU intensive server pause
void IO_CPU(float sec, int n) {
  usleep((int)(sec * 1e6));
  for (int i = 0; i < n; i++) {
    int x = i * i;
  }
}

// server thread function
void *start_function(void *arg) {
  int newsockfd = *(int *)arg;
  free(arg);

  char buffer[256];
  int n;

  /* read message from client */
  bzero(buffer, 256);
  n = read(newsockfd, buffer, 255);
  if (n < 0)
    error("ERROR reading from socket");

  /* switch between different forms of server */
  // IO(2);
  // CPU(1e7);
  IO_CPU(2, 1e7);

  /* send reply to client */
  n = write(newsockfd, "I got your message", 19);
  if (n < 0)
    error("ERROR writing to socket");

  /* log in stout */
  printf("Received: %s", buffer);

  /* close socket */
  close(newsockfd);
  pthread_exit(NULL);
  pthread_detach(pthread_self());
}

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  if (argc < 2) {
    fprintf(stderr, "ERROR, no port provided\n");
    exit(1);
  }

  /* create socket */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");

  /* set server attrs */
  bzero((char *)&serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  /* bind socket to this port number on this machine */
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");

  /* listen for incoming connection requests */
  n = listen(sockfd, 1);
  if (n < 0)
    error("ERROR on listen");

  clilen = sizeof(cli_addr);
  while (1) {
    /* accept a new request, create a newsockfd */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
      error("ERROR on accept");

    /* create a new thread to handle the client */
    int *arg = malloc(sizeof(int));
    *arg = newsockfd;
    pthread_t thread;
    if (pthread_create(&thread, NULL, start_function, (void *)arg) != 0)
      printf("Failed to create Thread\n");
  }

  return 0;
}

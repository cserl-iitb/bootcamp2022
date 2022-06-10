/* run client using: ./client localhost <server port> <concurrency> <think time>
 * <test duration> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <netdb.h>

void error(char *msg) {
  perror(msg);
  exit(0);
}

int main(int argc, char *argv[]) {
  int sockfd, portno, n;

  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[256];
  if (argc != 6) {
    fprintf(stderr,
            "Usage: %s <hostname> <server port> <number of concurrent users> "
            "<think time (in s)> <test duration (in s)>\n",
            argv[0]);
    exit(0);
  }

  printf("%s %s %s %s %s\n", argv[1], argv[2], argv[3], argv[4], argv[5]);

  /* create socket, get sockfd handle */

  portno = atoi(argv[2]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");

  /* fill in server address in sockaddr_in data structure */

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(0);
  }
  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);
  serv_addr.sin_port = htons(portno);

  /* connect to server */

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR connecting");

  /* ask user for input */

  printf("Please enter the message: ");
  bzero(buffer, 256);
  fgets(buffer, 255, stdin);

  /* send user message to server */

  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0)
    error("ERROR writing to socket");
  bzero(buffer, 256);

  /* read reply from server */

  n = read(sockfd, buffer, 255);
  if (n < 0)
    error("ERROR reading from socket");
  printf("Server response: %s\n", buffer);

  return 0;
}

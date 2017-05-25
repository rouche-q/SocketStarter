#ifndef _SOCKETSTARTER_H
#	define _SOCKETSTARTER_H

/* ##################
** #### INCLUDE ####
** ##################
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

typedef struct s_server {
  int fd_socket;
  int port;
  struct sockaddr_in s_in;
  struct sockaddr_in s_in_client;
  socklen_t s_in_size;
	int client_fd;
}              t_server;

/* ##################
** #### FUNCTION ####
** ##################
*/

int createSocket();
int bindSocket(int fd, struct sockaddr_in s_in);
int listenSocket(int fd);
int acceptSocket(int fd, struct sockaddr_in s_in_client, socklen_t s_in_size);
int connectSocket(int fd, struct sockaddr_in s_in);

struct sockaddr_in initPortServer(int port);

int getPort(char *port);

void doWhatYouWant(t_server);

#endif /* !_MY_IRC */

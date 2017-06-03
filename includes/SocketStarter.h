#ifndef _SOCKETSTARTER_H_
#	define _SOCKETSTARTER_H_

/*
**  INCLUDES
*/

#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

/*
**  STRUCTURES
*/

typedef struct 				s_server
{
  int 								port;
	int 								fd_socket;
	int 								fd_client;
	socklen_t 					s_in_size;
  struct sockaddr_in	s_in;
  struct sockaddr_in 	s_in_client;
}              				t_server;

/*
**  PROTOTYPES
*/

/*  main.c  */

int			usage(char *bin_name);

/*  init.c  */

int									getPort(char *port);
struct sockaddr_in	initPortServer(int port);

/*  socket.c  */

int 		createSocket();
int 		bindSocket(int fd, struct sockaddr_in s_in);
int 		listenSocket(int fd);
int 		acceptSocket(int fd, struct sockaddr_in s_in_client, socklen_t s_in_size);
int 		connectSocket(int fd, struct sockaddr_in s_in);

/*  dowhatyouwant.c  */

void 		doWhatYouWant(t_server);

#endif /* !_SOCKETSTARTER_H_ */

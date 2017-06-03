#include "SocketStarter.h"

int			createSocket()
{
	int 						fd;
  struct protoent *pe;

  if (!(pe = getprotobyname("TCP")))
	{
		perror("getprotobyname");
		exit(-1);
	}
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
	{
		perror("socket");
		exit(-1);
	}
	printf("Socket created\n");
  return (fd);
}

int			bindSocket(int fd, struct sockaddr_in s_in)
{
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
			perror("bind");
			exit(-1);
    }
  printf("Socket binded\n");
  return (0);
}

int			listenSocket(int fd)
{
  if (listen(fd, 1) == -1)
  {
		perror("listen");
		exit(-1);
  }
	printf("Listen\n");
  return (0);
}

int			acceptSocket(int fd, struct sockaddr_in s_in_client, socklen_t s_in_size)
{
  int 	fd_client;

  fd_client = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size);
  if (fd_client == -1)
    {
			perror("accept");
			exit(-1);
    }
  printf("Client accepted\n");
  return (fd_client);
}

int			connectSocket(int fd, struct sockaddr_in s_in)
{
  if (connect(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
			perror("connect");
			exit(-1);
    }
  printf("Client connected\n");
  return (0);
}

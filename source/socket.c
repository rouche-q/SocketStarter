#include "SocketStarter.h"

int createSocket()
{
  struct protoent *pe;
  int fd;

  if (!(pe = getprotobyname("TCP")))
    return (-1);
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
	printf("Created\n");
  return (fd);
}


int bindSocket(int fd, struct sockaddr_in s_in)
{
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      printf("Nop\n");
      if (close(fd) == -1)
        return (1);
      return (1);
    }
  printf("Binded\n");
  return (0);
}

int listenSocket(int fd)
{
  if (listen(fd, 1) == -1)
  {
		printf("Nop\n");
    if (close(fd) == -1)
      return (1);
    return (1);
  }
	printf("Listen\n");
  return (0);
}

int acceptSocket(int fd, struct sockaddr_in s_in_client, socklen_t s_in_size)
{
  int client_fd;

  client_fd = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size);
  if (client_fd == -1)
    {
      printf("Nop\n");
      if (close(fd) == -1)
        return (1);
      return (1);
    }
  printf("Accepted\n");
  return (client_fd);
}

int connectSocket(int fd, struct sockaddr_in s_in)
{
  if (connect(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      if (close(fd) == -1)
        return (1);
      return (1);
    }
  printf("Connected\n");
  return (0);
}

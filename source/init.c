#include "SocketStarter.h"

struct sockaddr_in initPortServer(int port)
{
  struct sockaddr_in s_in;

  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;

  return (s_in);
}

int getPort(char *port)
{
  return (atoi(port));
}

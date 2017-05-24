#include "SocketStarter.h"

int usage(int argc, char *bin_name)
{
  if (argc != 2)
  {
    printf("%s  [PORT]\n", bin_name);
		printf("[PORT] : The port number must be greater than 1024\n");
    return (1);
  }
  return (0);
}

int main(int argc, char ** argv)
{
 	t_server server;

 	if (usage(argc, argv[0]))
    	return (0);

  server.fd_socket = createSocket();									/* Create the socket (man socket)*/
  server.port = getPort(argv[1]);
  server.s_in = initPortServer(server.port);
  bindSocket(server.fd_socket, server.s_in);			 		/* Bind a socket (man bind) */
  listenSocket(server.fd_socket); 										/* Start to listen for incomming connexion*/
  while (1) 																					/*  Use this infinite loop to accept multiple connection*/
  {
    server.client_fd = acceptSocket(server.fd_socket, server.s_in_client, /* Accept incomming connection */
                server.s_in_size);
		doWhatYouWant(server);                                                /* Now, you can do what you whant */
  }
  return (0);
}

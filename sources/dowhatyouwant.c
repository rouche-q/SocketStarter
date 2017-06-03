#include "SocketStarter.h"

void 		doWhatYouWant(t_server server)
{
	write(server.fd_client, "Hello !\n", strlen("Hello !\n"));
	write(server.fd_client,
		"You are connected on a server created with SocketStarter !\n",
		strlen("You are connected on a server created with SocketStarter !\n"));
	close(server.fd_client);
}

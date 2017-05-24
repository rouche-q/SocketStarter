#include "SocketStarter.h"

void doWhatYouWant(t_server server)
{
	write(server.client_fd, "Hello !\n", strlen("Hello !\n"));
	write(server.client_fd,
		"You are connected on a server created with SocketStarter !\n",
		strlen("You are connected on a server created with SocketStarter !\n"));
	close(server.client_fd);
	return;
}

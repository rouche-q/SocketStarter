/*
** init.c for my_ftp in /home/rouche_q/rendu/PSU_2016_myftp/source/
**
** Made by Quentin Rouchet
** Login   <rouche_q@epitech.eu>
**
** Started on  Sat May 13 19:02:28 2017 Quentin Rouchet
** Last update	Wed May 24 17:07:25 2017 Full Name
*/

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

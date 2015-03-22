/*
** main.c for minitalk in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minitalk/Server
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Mar 16 19:13:56 2015 Boulay Arnaud
** Last update Fri Mar 20 16:16:30 2015 Boulay Arnaud
*/

#include <unistd.h>
#include <signal.h>
#include "server.h"

int		g_pid;

int		main(void)
{
  pid_t		pid;

  g_pid = 0;
  pid = getpid();
  my_putstr("My PID is : ");
  my_putnbr(pid);
  my_putchar('\n');
  my_putstr("Now catching signals.\n");
  while (1)
    {
      signal(SIGUSR1, catch_signal);
      signal(SIGUSR2, catch_signal);
      if (usleep(300000) == 0)
	g_pid = 0;
    }
  return (0);
}

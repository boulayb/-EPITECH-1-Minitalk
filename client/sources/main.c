/*
** main.c for minitalk in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minitalk/Client
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Mar 16 19:13:24 2015 Boulay Arnaud
** Last update Sun Mar 22 12:41:23 2015 Boulay Arnaud
*/

#include "client.h"

int	my_client(int pid, char *str)
{
  if (send_pid(pid) == -1 || send_len(pid, my_strlen(str)) == -1)
    {
      my_putstr("Error: kill failed in my_client.\n");
      return (-1);
    }
  if (send_message(pid, str) == -1)
    return (-1);
  my_putstr("Done.\n");
  return (0);
}

int	main(int ac, char **av)
{
  int	pid;

  if (ac == 3)
    {
      pid = my_getnbr(av[1]);
      if (pid <= 0)
	{
	  my_putstr("Syntax Error: Invalid PID.\n");
	  return (-1);
	}
      my_putstr("Sending \"");
      my_putstr(av[2]);
      my_putstr("\" to PID ");
      my_putnbr(pid);
      my_putchar('\n');
      if (my_client(pid, av[2]) == -1)
	return (-1);
    }
  else
    my_putstr("Syntax Error: ./client pid message\n");
  return (0);
}

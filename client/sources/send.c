/*
** send.c for minitalk in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minitalk/Client
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Fri Mar 20 16:19:35 2015 Boulay Arnaud
** Last update Sun Mar 22 13:01:45 2015 Boulay Arnaud
*/

#include <signal.h>
#include <unistd.h>
#include "client.h"

int	send_end(int pid)
{
  int	ret;

  ret = send_char(pid, '\0');
  if (ret == -1)
    {
      my_putstr("Error: kill failed in send_char.\n");
      return (-1);
    }
  else if (ret == -2)
    {
      my_putstr("Error: Client timed out.\n");
      return (-1);
    }
  return (0);
}

int	send_message(int pid, char *str)
{
  int	i;
  int	ret;

  i = -1;
  while (str[++i] != '\0')
    {
      ret = send_char(pid, str[i]);
      if (ret == -1)
	{
	  my_putstr("Error: kill failed in send_char.\n");
	  return (-1);
	}
      else if (ret == -2)
	{
	  my_putstr("Error: Client timed out.\n");
	  return (-1);
	}
    }
  if (send_end(pid) == -1)
    return (-1);
  return (0);
}

int	send_len(int pid, int len)
{
  int	i;
  int	bit;

  i = 32;
  while (--i >= 0)
    {
      bit = len & (1 << i);
      if (bit > 0)
	{
	  if (kill(pid, SIGUSR2) == -1)
	    return (-1);
	}
      else
	if (kill(pid, SIGUSR1) == -1)
	  return (-1);
      usleep(1);
    }
  return (0);
}

int	send_pid(int pid)
{
  int	i;
  int	bit;
  int	my_pid;

  i = 32;
  my_pid = getpid();
  my_putstr("My PID is : ");
  my_putnbr(my_pid);
  my_putchar('\n');
  while (--i >= 0)
    {
      bit = my_pid & (1 << i);
      if (bit > 0)
	{
	  if (kill(pid, SIGUSR2) == -1)
	    return (-1);
	}
      else
	if (kill(pid, SIGUSR1) == -1)
	  return (-1);
      usleep(1);
    }
  return (0);
}

int	send_char(int pid, char c)
{
  int	i;
  int	bit;

  i = 8;
  while (--i >= 0)
    {
      bit = c & (1 << i);
      if (bit > 0)
	{
	  if (kill(pid, SIGUSR2) == -1)
	    return (-1);
	}
      else
	if (kill(pid, SIGUSR1) == -1)
	  return (-1);
      if (c != '\0' || i != 0)
	{
	  signal(SIGUSR2, catch_signal);
	  if (usleep(300000) == 0)
	    return (-2);
	}
      usleep(10);
    }
  return (0);
}

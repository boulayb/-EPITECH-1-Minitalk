/*
** get.c for minitalk in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minitalk/Server
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Fri Mar 20 16:04:52 2015 Boulay Arnaud
** Last update Sun Mar 22 13:45:34 2015 Boulay Arnaud
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"

int		get_pid(int signal)
{
  static int	tmp_pid = 0;
  static int	pid = 0;
  static int	i = 32;

  if (tmp_pid != g_pid)
    reset_get_pid(&tmp_pid, &pid, &i);
  if (--i >= 0)
    {
      if (signal == SIGUSR1)
	pid = pid << 1;
      else if (signal == SIGUSR2)
	pid = (pid << 1) | 1;
    }
  if (i <= 0)
    {
      g_pid = pid;
      my_putstr("Catching signals from PID : ");
      my_putnbr(g_pid);
      my_putchar('\n');
      pid = 0;
      i = 32;
    }
  return (0);
}

char		*get_len(int signal, char *buff, int *len)
{
  static int	tmp_pid = 0;
  static int	tmp;
  static int	i;

  if (tmp_pid != g_pid)
    reset_get_len(&tmp_pid, &tmp, &i);
  if (--i >= 0)
    {
      if (signal == SIGUSR1)
	tmp = tmp << 1;
      else if (signal == SIGUSR2)
	tmp = (tmp << 1) | 1;
    }
  if (i <= 0)
    {
      *len = tmp + 1;
      buff = my_malloc(buff, *len);
      i = 32;
      tmp = 0;
      return(buff);
    }
  return (NULL);
}

void		disp_buff(char *buff, int *len, int *j)
{
  write(1, buff, *len);
  my_putchar('\n');
  g_pid = 0;
  *j = -1;
  *len = 0;
  free(buff);
}

void		add_char(char *c, int *i, char *buff, int *len)
{
  static int	tmp_pid = 0;
  static int	j;

  if (tmp_pid != g_pid)
    reset_add_char(&tmp_pid, &j);
  if (++j < *len)
    buff[j] = *c;
  else
    {
      my_putstr("Error: buffer limit reached.\n");
      g_pid = 0;
      j = -1;
      *len = 0;
      free(buff);
    }
  if (*c == '\0')
    disp_buff(buff, len, &j);
  *i = 8;
  *c = 0;
}

int		get_char(int signal, char *buff, int *len)
{
  static int	tmp_pid = 0;
  static int	i;
  static char	c;

  if (tmp_pid != g_pid)
    {
      i = 8;
      c = 0;
      tmp_pid = g_pid;
    }
  if (--i >= 0)
    {
      if (signal == SIGUSR1)
	c = c << 1;
      else if (signal == SIGUSR2)
	c = (c << 1) | 1;
    }
  usleep(10);
  send_signal();
  if (i <= 0)
    add_char(&c, &i, buff, len);
  return (0);
}

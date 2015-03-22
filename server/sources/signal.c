/*
** signal.c for minitalk in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minitalk/Server
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Fri Mar 20 16:03:40 2015 Boulay Arnaud
** Last update Sun Mar 22 13:23:23 2015 Boulay Arnaud
*/

#include <signal.h>
#include <stdlib.h>
#include "server.h"

void		send_signal()
{
  if (kill(g_pid, SIGUSR2) == -1)
    my_putstr("\nWarning: can't reach client or kill failed in send_signal.\n");
}

void		catch_signal(int signal)
{
  static int	tmp_pid = 0;
  static int	len = 0;
  static char	*buff = NULL;

  if (tmp_pid != g_pid)
    {
      len = 0;
      buff = NULL;
      tmp_pid = g_pid;
    }
  if (g_pid == 0)
    get_pid(signal);
  else if (len == 0)
    buff = get_len(signal, buff, &len);
  else
    get_char(signal, buff, &len);
}

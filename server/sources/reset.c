/*
** reset.c for minitalk in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minitalk/Server
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Sun Mar 22 13:28:41 2015 Boulay Arnaud
** Last update Sun Mar 22 13:32:27 2015 Boulay Arnaud
*/

#include "server.h"

void	reset_get_pid(int *tmp_pid, int *pid, int *i)
{
  *pid = 0;
  *i = 32;
  *tmp_pid = g_pid;
}

void	reset_get_len(int *tmp_pid, int *tmp, int *i)
{
  *tmp = 0;
  *i = 32;
  *tmp_pid = g_pid;
}

void	reset_add_char(int *tmp_pid, int *j)
{
  *j = -1;
  *tmp_pid = g_pid;
}

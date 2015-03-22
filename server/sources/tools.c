/*
** tools.c for minitalk in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minitalk/Server
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Mar 16 23:06:03 2015 Boulay Arnaud
** Last update Sun Mar 22 13:45:10 2015 Boulay Arnaud
*/

#include <unistd.h>
#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    my_putchar(str[i]);
}

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    ;
  return (i);
}

void	my_putnbr(int nb)
{
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + 48);
}

char	*my_malloc(char *buff, int size)
{
  if ((buff = malloc(sizeof(char) * size)) == NULL)
    {
      my_putstr("Error: Malloc failed in get_len.\n");
      exit(-1);
    }
  return (buff);
}

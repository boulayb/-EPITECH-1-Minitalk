/*
** tools.c<Client> for minitalk in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minitalk/Client
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Mar 16 23:30:15 2015 Boulay Arnaud
** Last update Mon Mar 16 23:30:32 2015 Boulay Arnaud
*/

#include <unistd.h>

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

int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  if (str == NULL)
    return (0);
  i = -1;
  nb = 0;
  while (str[++i] != '\0')
    if (str[i] < '0' || str[i] > '9')
      return (0);
    else if (str[i + 1] == '\0')
      nb = nb + (str[i] - 48);
    else
      nb = (nb * 10) + ((str[i] - 48) * 10);
  return (nb);
}

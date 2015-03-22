/*
** client.h for minitalk in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minitalk/Client
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Mar 16 23:34:11 2015 Boulay Arnaud
** Last update Sun Mar 22 01:47:26 2015 Boulay Arnaud
*/

#ifndef	CLIENT_H_
# define CLIENT_H_

int	send_pid(int pid);
int	send_char(int pid, char c);
int	my_getnbr(char *str);
int	my_strlen(char *str);
int	send_message(int pid, char *str);
int	send_len(int pid, int len);
void	my_putchar(char c);
void	my_putnbr(int nb);
void	my_putstr(char *str);
void	catch_signal(int signal);

#endif /* !CLIENT_H_ */

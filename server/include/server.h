/*
** server.h for minitalk in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minitalk/Server/include
**
** Made by Boulay Arnaud
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Mar 16 23:10:09 2015 Boulay Arnaud
** Last update Sun Mar 22 13:42:16 2015 Boulay Arnaud
*/

#ifndef	SERVER_H_
# define SERVER_H_

extern int	g_pid;

int		get_pid(int signal);
int		get_char(int signal, char *buff, int *len);
char		*get_len(int signal, char *buff, int *len);
char		*my_malloc(char *buff, int size);
void		my_putnbr(int nb);
void		my_putchar(char c);
void		my_putstr(char *str);
void		catch_signal(int signal);
void		send_signal(void);
void		reset_get_pid(int *tmp_pid, int *pid, int *i);
void		reset_get_len(int *tmp_pid, int *tmp, int *i);
void		reset_add_char(int *tmp_pid, int *j);

#endif /* !SERVER_H_ */

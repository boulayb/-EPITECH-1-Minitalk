##
## Makefile for minitalk in /home/boulay_b/Rendu/SE2/PSU/PSU_2014_minitalk
##
## Made by Boulay Arnaud
## Login   <boulay_b@epitech.net>
##
## Started on  Mon Mar 16 19:01:04 2015 Boulay Arnaud
## Last update Sun Mar 22 14:02:46 2015 Boulay Arnaud
##

NAME1	= server/server

NAME2	= client/client

SSRCFO	= server/sources/

CSRCFO	= client/sources/

SSRCS	= $(SSRCFO)main.c \
	  $(SSRCFO)get.c \
	  $(SSRCFO)signal.c \
	  $(SSRCFO)reset.c \
	  $(SSRCFO)tools.c

CSRCS	= $(CSRCFO)main.c \
	  $(CSRCFO)send.c \
	  $(CSRCFO)signal.c \
	  $(CSRCFO)tools.c

SOBJS	= $(SSRCS:.c=.o)

COBJS	= $(CSRCS:.c=.o)

CFLAGS	= -Iserver/include/ -Iclient/include/ -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1): $(SOBJS)
	cc -o $(NAME1) $(SOBJS) $(CFLAGS)

$(NAME2): $(COBJS)
	cc -o $(NAME2) $(COBJS) $(CFLAGS)

clean:
	rm -rf $(SOBJS)
	rm -rf $(COBJS)

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)

re: fclean all

.PHONY: all clean fclean re

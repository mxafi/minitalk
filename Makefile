# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 13:11:28 by malaakso          #+#    #+#              #
#    Updated: 2023/02/05 18:12:30 by malaakso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client
CC = cc
CFLGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLGS)
SRCS = client.c server.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME) $(NAME2)

$(NAME): server.o libft/libft.a
	$(COMPILE) server.o libft/libft.a -o $(NAME)

$(NAME2): client.o libft/libft.a
	$(COMPILE) client.o libft/libft.a -o $(NAME2)

%.o: %.c
	$(COMPILE) $< -I libft -c

libft/libft.a:
	$(MAKE) -C libft

.PHONY: clean

clean:
	/bin/rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME2)
	$(MAKE) -C libft fclean

re: fclean all

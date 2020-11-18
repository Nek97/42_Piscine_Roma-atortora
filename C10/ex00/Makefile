# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atortora <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 09:11:31 by atortora          #+#    #+#              #
#    Updated: 2020/11/12 09:11:35 by atortora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	= -Wall -Wextra -Werror

NAME	= ft_display_file
SRCS	= main.c 
OBJS	= $(SRCS:.c=.o)
CC		= gcc

all: $(NAME)

%.o: %.c
	${CC} $(CFLAGS) -c $<

$(NAME): $(OBJS)
	${CC} $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 14:32:35 by jquicuma          #+#    #+#              #
#    Updated: 2024/08/03 14:37:49 by jquicuma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRC = ./src/

SRCS = $(SRC)*.c

RM = rm -f

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:

fclean:	clean
	$(RM) $(NAME)

re: fclean all
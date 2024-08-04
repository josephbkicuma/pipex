# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 14:32:35 by jquicuma          #+#    #+#              #
#    Updated: 2024/08/04 06:28:30 by jquicuma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRC = ./src/

SRCS = $(SRC)*.c

OBJ = ./obj/

OBJS = $(OBJ)*.o

RM = rm -f

MK = mkdir

MV = mv *.o $(OBJ)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	$(MK) $(OBJ)
	$(MV)

clean:
	$(RM) -r $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
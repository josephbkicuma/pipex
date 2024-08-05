# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 14:32:35 by jquicuma          #+#    #+#              #
#    Updated: 2024/08/05 12:13:44 by jquicuma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

SRC = ./src/

SRCS = $(SRC)*.c

OBJ = ./obj/

OBJS = $(OBJ)*.o

LIBFT_DIR = ./libft/

LIBFT_A = $(LIBFT_DIR)libft.a

MAKE_LIBFT	= make -s -C $(LIBFT_DIR)

RM = rm -f

MK = mkdir

MV = mv *.o $(OBJ)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE_LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -L.$(LIBFT_DIR) $(LIBFT_A) -o $(NAME) 

$(OBJS):	$(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	$(MK) $(OBJ)
	$(MV)

clean:
	$(RM) -r $(OBJ)
	$(MAKE_LIBFT) clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all
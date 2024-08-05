NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ./src/

SRCS = $(SRC)*.c

OBJS = $(SRC)*.o

F_OBJ = ./obj/

OBJ = *.o

F_OBJS = $(F_OBJ)*.o

AR = ar rcs

RM = rm -f

$(NAME): $(OBJS)
	$(AR) $(NAME) $(F_OBJS)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $(SRCS)
	mkdir $(F_OBJ)
	mv $(OBJ) $(F_OBJ)

clean:
	$(RM) -r $(F_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

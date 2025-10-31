CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = cub3D

SRC = parsing/parsing.c

OBJ = $(SRC:.c=.o)

all = $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $> -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: clean fclean all


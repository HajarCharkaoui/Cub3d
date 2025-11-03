CC = cc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

NAME = cub3D

SRC = parsing/parsing.c parsing/get_next_line.c parsing/utils.c \
	  parsing/clean_memory.c parsing/read_from_file.c parsing/colors.c\
	  libft/ft_atoi.c libft/ft_substr.c libft/ft_split.c libft/ft_strchr.c libft/ft_lstadd_back.c\
	  libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strncmp.c \
	  libft/ft_strtrim.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.c cub3d.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHOMY: all clean fclean re
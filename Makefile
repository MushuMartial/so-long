NAME = so_long
SRC = main.c mlx_utils.c hooks_utils.c parser.c check.c
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit
CC = gcc
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
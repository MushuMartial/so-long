NAME = so_long
SRC = main.c parser.c check.c background.c move.c
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
LINKS = -lmlx -framework OpenGL -framework AppKit
CC = gcc
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LINKS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
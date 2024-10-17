CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC_DIR = src
INCLUDE_DIR = include

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)
HEADER = $(wildcard $(INCLUDE_DIR)/*.h)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
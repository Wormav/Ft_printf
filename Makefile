CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC_DIR = src
INCLUDE_DIR = include

SRC = $(SRC_DIR)/decimal_convert.c $(SRC_DIR)/ft_printf.c $(SRC_DIR)/string_convert.c $(SRC_DIR)/utils.c
OBJ = $(SRC:.c=.o)
HEADER = $(INCLUDE_DIR)/ft_printf.h

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
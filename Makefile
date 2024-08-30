CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC_DIR = src
SRC_BONUS_DIR = src_bonus
INCLUDE_DIR = include
INCLUDE_BONUS_DIR = include_bonus

SRC = $(wildcard $(SRC_DIR)/*.c)
SRCB = $(wildcard $(SRC_BONUS_DIR)/*_bonus.c)
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
HEADER = $(wildcard $(INCLUDE_DIR)/*.h)
HEADER_BONUS = $(wildcard $(INCLUDE_BONUS_DIR)/*_bonus.h)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJB)
	ar rcs $(NAME) $(OBJ) $(OBJB)

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I $(INCLUDE_BONUS_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
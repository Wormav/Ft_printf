CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf.a

SRC_DIR = src
SRC_BONUS_DIR = src_bonus
INCLUDE_DIR = include
INCLUDE_BONUS_DIR = include_bonus
LIBFT_DIR = libft

SRC = $(wildcard $(SRC_DIR)/*.c)
SRCB = $(wildcard $(SRC_BONUS_DIR)/*_bonus.c)
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
HEADER = $(wildcard $(INCLUDE_DIR)/*.h)
HEADER_BONUS = $(wildcard $(INCLUDE_BONUS_DIR)/*_bonus.h)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) $(LIBFT)

bonus: $(OBJ) $(OBJB)
	ar rcs $(NAME) $(OBJ) $(OBJB) $(LIBFT)

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -I $(INCLUDE_BONUS_DIR) -I $(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
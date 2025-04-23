NAME = libftprintf.a
CC = CC
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf
OBJ = $(SRC:.c = .o)
AR = ar rcs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

clean :
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
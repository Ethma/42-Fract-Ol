NAME	 = fractol
CC		 = gcc
O_DIR	 = $(FILES:.c=.o)
CFLAGS	 = -Wall -Wextra -Werror
FILES	 = main.c \

L        = -L./libft/ -lft -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit \

RM		 = rm -f

all: $(NAME)

$(NAME): $(FILES)
		make -C libft/
		make -C minilibx_macos/
		$(CC) -c $(FILES)
		$(CC) $(O_DIR) $(L) -o $(NAME)
clean:
	$(RM) $(O_DIR)

fclean: 	clean
	$(RM) $(NAME)
	make fclean -C libft/
	make clean -C minilibx_macos/

libfclean:
	make fclean -C libft/

re:			fclean all

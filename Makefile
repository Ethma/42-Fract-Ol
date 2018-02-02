NAME	 = fractol
CC		 = gcc
O_DIR	 = $(FILES:.c=.o)
CFLAGS	 = -Wall -Wextra -Werror
FILES	 = main.c \
fractales.c \
draw.c \
hooks.c \
exit.c \

L        = -L./libft/ -lft -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit \

RM		 = rm -f

all: header $(NAME)

$(NAME): $(FILES)
	@tput cnorm
	@echo ""
	@echo ""
	make -C libft/
	make -C minilibx_macos/
	$(CC) -c $(FILES)
	$(CC) $(O_DIR) $(L) -o $(NAME)
	@echo "./[0;34m$(NAME)[0;38m created."
	@tput cnorm
clean:
	$(RM) $(O_DIR)
	@echo "[0;1mClear."

fclean: 	clean
	$(RM) $(NAME)
	make fclean -C libft/
	make clean -C minilibx_macos/
	@echo "[0;1mClear."

libfclean:
	make fclean -C libft/

header:
	@tput civis
	@clear
	@echo ""
	@echo "                     [0;34m  __  __       _        _____ _ _      "
	@echo "                      |  \/  | __ _| | _____|  ___(_) | ___ "
	@echo "                      | |\/| |/ _\` | |/ / _ \ |_  | | |/ _ \\"
	@echo "                      | |  | | (_| |   <  __/  _| | | |  __/"
	@echo "                      |_|  |_|\__,_|_|\_\___|_|   |_|_|\___|"
	@echo ""
	@echo ""
	@echo "[0;38mCompiling $(NAME)"
	@echo "[0;31m["
	@tput cup 9 $$(($(COUNTER) + 2))
	@echo "][0;36m"
	@tput cup 9 1
	@tput cnorm

re:			fclean all

.PHONY: re clean fclean all
NAME	 = fractol
CC		 = gcc
OBJ_NAME = $(FILES:.c=.o)
OBJ_PATH = ./obj
CFLAGS	 = -Wall -Wextra -Werror
SRC_PATH = ./src
INCLUDE = -I./include
FILES	 = main.c \
fractales.c \
draw.c \
hooks.c \
exit.c \
julia.c \
mandelbrot.c \
burningship.c \
frog.c \
slip.c \
test.c \
clean.c \
move.c
SRC = $(addprefix $(SRC_PATH)/,$(FILES))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
L        = -L./libft/ -lft -L./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
RM		 = rm -f

all: header $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@tput cnorm
	@echo ""
	@echo ""
	make -C libft/
	make -C minilibx_macos/
	$(CC) $(CFLAGS) $(OBJ) $(L) -o $(NAME)
	@echo "./[0;34m$(NAME)[0;38m created."
	@tput cnorm
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $? $(INCLUDE) -o $@
clean:
	rm -rf $(OBJ_PATH)
	@echo "[0;1mClear."
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 
fclean: 	clean
	$(RM) $(NAME)
	make fclean -C libft/
	make clean -C minilibx_macos/
	@echo "[0;1mClear."

libfclean:
	make fclean -C libft/
	@echo "[0;1mClear."

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

.PHONY: re clean fclean all bjr
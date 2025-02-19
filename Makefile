NAME		= fractol

SRC			= 	./src/main.c ./src/setup_fractol.c ./src/choose_fractol.c ./src/mouse_and_close.c \
 				./src/keyboard.c ./src/print_message.c ./src/color_scheme_basic.c ./src/color_scheme_extra.c

CC			= cc 
RM			= rm -f

OBJ				= $(SRC:.c=.o)
LIBFT 			= ./libft/libft.a

INC    			= -I./src

CFLAGS			= -Wall -Wextra -Werror -g
MLXFLAGS		= -O3 -Lmlx/ -lmlx -L/usr/lib -Ilmlx -lXext -lX11 -lm -lz

WHITE="\033[1m"
PURPLE:="\033[1;35m"
PINK="\033[95m"
RED="\033[1;91m"
GREEN:="\033[1;32m"
BLUE:="\033[1;36m"
ORANGE="\033[1;38;5;208m"
YELLOW="\033[1;33m"
EOC:="\033[0;0m" #END OF COLOR

all:		$(NAME)
			@echo
			@echo $(PINK) "*KEYBOARD INSTRUCTIONS*" $(EOC) $(RED)
			@echo "R: shifting color red" $(EOC) $(GREEN)
			@echo "G: shifting color green" $(EOC) $(BLUE)
			@echo "B: shifting color blue" $(EOC) $(WHITE)
			@echo "1-7: changing color scheme" $(EOC) $(YELLOW)
			@echo "Z, X, I, O: changing image sharpness" $(EOC) $(ORANGE)
			@echo "W, A, S, D: changing Julia set" $(EOC) $(PINK)
			@echo
			@echo $(PURPLE)
			@echo "✨The program is ready✨" $(EOC)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME):	$(LIBFT) $(OBJ)
	@echo $(BLUE) "*Compiling fract-ol*" $(EOC) $(GREEN) 
	$(CC) $(SRC) $(INC) $(MLXFLAGS) $(LIBFT) $(CFLAGS) -o $(NAME) - lm

$(OBJ): ./src/fractol.h

clean:
	@echo $(PURPLE) "🧽🧼" $(EOC)
	$(MAKE) -C ./libft clean
	$(RM) $(OBJ)
	@echo $(PURPLE) "✨Clean✨" $(EOC)

fclean:		clean
	@echo $(PURPLE) "🛁🧴" $(EOC)
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean
	@echo $(PURPLE) "✨FClean✨" $(EOC)

re:	fclean all

#ARGS		= Mandelbrot
#gdb:	all
#		gdb --args $(NAME) $(ARGS)
# valgrind: 	all
# 			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

.PHONY:		all clean fclean re

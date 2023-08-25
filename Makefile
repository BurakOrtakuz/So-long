NAME    =   so_long
CC      =   gcc
FLAGS   =   -Wall -Wextra -Werror
SRC     =   ./map_validations/map_validation.c \
            ./map_validations/variables.c \
            ./utils/ft_split.c \
            ./utils/so_long_utils.c \
			./utils/get_next_line/get_next_line_utils.c \
            ./utils/get_next_line/get_next_line.c \
            ./set_sprite.c \
			./main.c
MINILIBX_PATH       =   ./mlx
all:    			$(NAME)
$(NAME):			$(LIBFT) mlx
					$(CC) $(FLAGS) -o $(NAME) $(SRC) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH)
mlx:
					make -C $(MINILIBX_PATH) all
exe:				$(NAME)
					./so_long
clean:
					make -C $(MINILIBX_PATH) clean
fclean:				clean
					rm -rf $(NAME)
re:					fclean all
.PHONY:				all clean fclean re libft
NAME    =   so_long
CC      =   gcc
FLAGS   =   -Wall -Wextra -Werror
SRC     =   ./map_validations/map_validation.c \
            ./map_validations/variables.c \
			./map_validations/error_managament.c \
			./utils/so_long_utils_extra.c \
            ./utils/ft_split.c \
			./utils/ft_itoa.c \
            ./utils/so_long_utils.c \
			./utils/get_next_line/get_next_line_utils.c \
            ./utils/get_next_line/get_next_line.c \
			./enemy_animation_set.c \
			./enemy.c \
			./list.c \
			./animation.c \
            ./set_sprite.c \
			./key_hooks.c \
			./key_events.c \
			./main.c
MINILIBX_PATH       =   ./minilibx
all:    			$(NAME)
$(NAME):			$(LIBFT) mlx
					$(CC) $(FLAGS) -o $(NAME) $(SRC) -framework OpenGL -framework AppKit -L$(MINILIBX_PATH) -lmlx
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
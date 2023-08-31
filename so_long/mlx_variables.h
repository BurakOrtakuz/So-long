/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_variables.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:51:18 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/31 16:48:39 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_VARIABLES_H
# define MLX_VARIABLES_H

# include "so_long.h"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_all_sprites
{
	void	*pacman;
	void	*pacman_right;
	void	*pacman_down;
	void	*pacman_left;
	void	*pacman_up;
	void	*wall;
	void	*space;
	void	*coin;
	void	*exit;
}	t_all_sprites;

typedef struct s_game_variables
{
	int	moving;
	int	collected_coin;
	int	movement;
}	t_game_variables;

typedef struct s_program {
	void				*mlx;
	void				*window;
	t_all_sprites		sprites;
	t_map				*map;
	t_game_variables	game_variables;
}	t_program;

void	set_all_sprites(t_program *program);
void	set_key_hooks(t_program *program);

int		render_next_frame(t_program *program);
void	put_all_image(t_program *program);

void	keyboard_pressed(t_program *program);
int		key_down(int keycode, t_program *program);
int		key_up(int keycode, t_program *program);

int		exit_game(t_program *program, char *massage);
int		exit_game_mouse(t_program *program);
void	free_sprite(t_program *program);
#endif
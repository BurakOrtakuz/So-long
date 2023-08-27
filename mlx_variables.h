/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_variables.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:51:18 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/26 15:24:15 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_VARIABLES_H
# define MLX_VARIABLES_H

#include "so_long.h"

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_all_sprites
{
	t_image	pacman;
	t_image	wall;
	t_image	space;
	t_image	coin;
	t_image	exit;
}	t_all_sprites;

typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_program {
	void				*mlx;
	t_window			window;
	t_all_sprites		sprites;
}				t_program;

void	set_all_sprites(t_program *program);
void	put_all_image(t_program *program, t_map *map);

#endif
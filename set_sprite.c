/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:29:07 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/26 15:58:51 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_variables.h"
#include "so_long.h"
#include "./minilibx/mlx.h"
#include <stdio.h>

static void	*ft_new_sprite(void *mlx, char *path)
{
	return (mlx_xpm_file_to_image(mlx, path, &(int){0}, &(int){0}));
}

void	set_all_sprites(t_program *program)
{
	program->sprites.pacman.reference = ft_new_sprite(program->mlx,
			"./Sprites/Pac-Man/pac_semi_right.xpm");
	program->sprites.wall.reference = ft_new_sprite(program->mlx,
			"./Sprites/Other/Walls/wall.xpm");
	program->sprites.space.reference = ft_new_sprite(program->mlx,
			"./Sprites/Other/Walls/black.xpm");
	program->sprites.coin.reference = ft_new_sprite(program->mlx,
			"./Sprites/Other/Pacdots/pacdot_food.xpm");
	program->sprites.exit.reference = ft_new_sprite(program->mlx,
			"./Sprites/Other/Portal/portal.xpm");
}

void	check_map(char point, int i, int j, t_program *program)
{
	if (point == '1')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites.wall.reference, j * 32, i * 32);
	else if (point == '0')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites.space.reference, j * 32, i * 32);
	else if (point == 'P')
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites.pacman.reference, j * 32, i * 32);
	else if (point == 'C')
	{
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites.space.reference, j * 32, i * 32);
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites.coin.reference, j * 32, i * 32);
	}
	else if (point == 'E')
	{
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites.space.reference, j * 32, i * 32);
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->sprites.exit.reference, j * 32, i * 32);
	}
}

void	put_all_image(t_program *program, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i, i < map->map_y_lenght)
	{
		j = -1;
		while (++j, j < map->map_x_lenght)
		{
			check_map(map->map[i][j], i, j, program);
		}
	}
}

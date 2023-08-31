/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:45:10 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/31 14:50:36 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_variables.h"
#include "so_long.h"
#include "./minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

int	exit_game(t_program *program, char *massage)
{
	free_map(program->map->map);
	free_sprite(program);
	mlx_destroy_window(program->mlx, program->window);
	ft_putstr(massage, 1);
	ft_putstr("\n", 1);
	exit(0);
}

int	exit_game_mouse(t_program *program)
{
	exit_game(program, "You Closed The Game!!");
	return (0);
}

void	set_key_hooks(t_program *program)
{
	set_all_sprites(program);
	program->game_variables.collected_coin = 0;
	mlx_hook(program->window, 2, (1L << 0), key_down, program);
	mlx_hook(program->window, 3, (1L << 1), key_up, program);
	mlx_hook(program->window, 17, 0, exit_game_mouse, program);
	mlx_loop_hook(program->mlx, render_next_frame, program);
}

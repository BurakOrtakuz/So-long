/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:23:14 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/31 13:05:07 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_variables.h"
#include "./minilibx/mlx.h"
#include <stdlib.h>
#include "so_long.h"

int	key_down(int keycode, t_program *program)
{
	program->game_variables.moving = keycode;
	return (0);
}

int	key_up(int keycode, t_program *program)
{
	(void)keycode;
	program->game_variables.moving = -1;
	return (0);
}

void	move_helper(t_program *program, t_vector *way)
{
	program->map->map[way->x][way->y] = 'P';
	program->map->map[program->map->player.x][program->map->player.y] = '0';
	program->map->player.x = way->x;
	program->map->player.y = way->y;
	program->game_variables.movement++;
}

void	move(t_program *program, int x, int y)
{
	t_vector	way;
	char		symbol;

	way.x = program->map->player.x + x;
	way.y = program->map->player.y + y;
	symbol = program->map->map[way.x][way.y];
	if (symbol == 'C')
	{
		program->game_variables.collected_coin++;
		move_helper(program, &way);
		ft_putnbr(program->game_variables.movement);
		ft_putstr("\n", 1);
	}
	else if (symbol == '0')
	{
		program->map->map[way.x][way.y] = 'P';
		move_helper(program, &way);
		ft_putnbr(program->game_variables.movement);
		ft_putstr("\n", 1);
	}
	else if (symbol == 'E' && 
		program->game_variables.collected_coin == program->map->coin)
		exit_game(program);
}

int	render_next_frame(t_program *program)
{
	static int	fps = 0;

	if (fps % 800 == 0)
	{
		if (program->map->ghosts.x)
			move_ghost(program);
		keyboard_pressed(program);
		fps = 0;
	}
	if (fps % 700 == 0)
	{
		program->sprites.pacman = program->sprites.pacman->next;
		mlx_clear_window(program->mlx, program->window);
		put_all_image(program);
	}
	if (fps == 5600)
		fps = 0;
	fps++;
	return (0);
}

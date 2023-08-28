/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:02:43 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/28 18:06:26 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_variables.h"
#include "list.h"

void	set_animation_sprites(t_program *program)
{
	ft_lstadd_back(&program->sprites.pacman_down, program->mlx,
		"./Sprites/Pac-Man/pac_open_down.xpm");
	ft_lstadd_back(&program->sprites.pacman_down, program->mlx,
		"./Sprites/Pac-Man/pac_semi_down.xpm");
	ft_lstadd_back(&program->sprites.pacman_down, program->mlx,
		"./Sprites/Pac-Man/pac_closed.xpm");
	ft_lstadd_back(&program->sprites.pacman_left, program->mlx,
		"./Sprites/Pac-Man/pac_open_left.xpm");
	ft_lstadd_back(&program->sprites.pacman_left, program->mlx,
		"./Sprites/Pac-Man/pac_semi_left.xpm");
	ft_lstadd_back(&program->sprites.pacman_left, program->mlx,
		"./Sprites/Pac-Man/pac_closed.xpm");
	ft_lstadd_back(&program->sprites.pacman_right, program->mlx,
		"./Sprites/Pac-Man/pac_open_right.xpm");
	ft_lstadd_back(&program->sprites.pacman_right, program->mlx,
		"./Sprites/Pac-Man/pac_semi_right.xpm");
	ft_lstadd_back(&program->sprites.pacman_right, program->mlx,
		"./Sprites/Pac-Man/pac_closed.xpm");
	ft_lstadd_back(&program->sprites.pacman_up, program->mlx,
		"./Sprites/Pac-Man/pac_open_up.xpm");
	ft_lstadd_back(&program->sprites.pacman_up, program->mlx,
		"./Sprites/Pac-Man/pac_semi_up.xpm");
	ft_lstadd_back(&program->sprites.pacman_up, program->mlx,
		"./Sprites/Pac-Man/pac_closed.xpm");
}

void	keyboard_pressed_helper(t_program *program, int x, int y, int last_move)
{
	move(program, x, y);
	if (program->game_variables.last_move != -1)
	{
		if (x == 1 && program->game_variables.last_move != 1)
			program->sprites.pacman = program->sprites.pacman_down;
		else if (x == -1 && program->game_variables.last_move != 13)
			program->sprites.pacman = program->sprites.pacman_up;
		else if (y == 1 && program->game_variables.last_move != 2)
			program->sprites.pacman = program->sprites.pacman_right;
		else if (y == -1 && program->game_variables.last_move != 0)
			program->sprites.pacman = program->sprites.pacman_left;
	}
	program->game_variables.last_move = last_move;
}

void	keyboard_pressed(t_program *program)
{
	if (program->game_variables.moving == 0)
	{
		keyboard_pressed_helper(program, 0, -1, 0);
	}
	else if (program->game_variables.moving == 2)
	{
		keyboard_pressed_helper(program, 0, 1, 2);
	}
	else if (program->game_variables.moving == 13)
	{
		keyboard_pressed_helper(program, -1, 0, 13);
	}
	else if (program->game_variables.moving == 1)
	{
		keyboard_pressed_helper(program, 1, 0, 1);
	}
}

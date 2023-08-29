/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:50:31 by burak             #+#    #+#             */
/*   Updated: 2023/08/29 17:22:14 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils/get_next_line/get_next_line.h"
#include <stdlib.h>
#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "mlx_variables.h"
#include "./minilibx/mlx.h"

int	main(int ac, char **av)
{
	t_map		map;
	t_program	program;

	map.map = is_file_valid(ac, av);
	calculate_things(&map);
	program.mlx = mlx_init();
	program.map = &map;
	program.window = mlx_new_window(program.mlx, 
			32 * map.map_x_lenght, 32 * (map.map_y_lenght) + 121, "so_long");
	set_key_hooks(&program);
	mlx_loop(program.mlx);
}

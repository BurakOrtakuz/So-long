/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:50:31 by burak             #+#    #+#             */
/*   Updated: 2023/08/26 17:44:01 by bortakuz         ###   ########.fr       */
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
	/*
	printf("Coins = %d Player x = %d Player y = %d Exit x = %d Exit y = %d\n",
		map.coin, map.player.x, map.player.y, map.exit.x, map.exit.y);
	printf("----------------------------------\n");
	i = 0;
	while (map.map[i])
	{
		ft_putstr(map.map[i], 1);
		ft_putstr("\n", 1);
		i++;
	}
	printf("----------------------------------\n");
	*/
	
	program.mlx = mlx_init();
	program.window.reference = mlx_new_window(program.mlx, 
			32 * map.map_x_lenght, 32* map.map_y_lenght, "so_long");
	set_all_sprites(&program);
	put_all_image(&program, &map);
	mlx_loop(program.mlx);
}

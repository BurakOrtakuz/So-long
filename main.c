/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:50:31 by burak             #+#    #+#             */
/*   Updated: 2023/08/13 20:34:37 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include <stdlib.h>
#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	t_map	map;
	int		i;

	map.map = is_file_valid(ac, av);
	calculate_things(&map);
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
}

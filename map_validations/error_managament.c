/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managament.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:02:54 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/27 18:51:41 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

void	free_map(char **map)
{
	int	ecx;

	ecx = -1;
	while (++ecx, map[ecx])
	{
		free(map[ecx]);
		map[ecx] = (void *)0;
	}
	free(map);
	map = (void *)0;
}

void	error_massage(char *str, char **map)
{
	ft_putstr("Error\n", 1);
	ft_putstr(str, 1);
	if (map)
		free_map(map);
	exit(-1);
}

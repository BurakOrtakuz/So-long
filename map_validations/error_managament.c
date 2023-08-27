/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managament.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:02:54 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/27 15:06:50 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

void	free_map(char **map)
{
	if (map[1])
		free_map(&map[1]);
	if (map)
		free(map[0]);
}

void	error_massage(char *str, char **map)
{
	ft_putstr("Error\n", 1);
	ft_putstr(str, 1);
	if (map)
		free_map(map);
	exit(-1);
}

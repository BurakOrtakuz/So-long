/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 23:34:37 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/24 02:00:10 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static char	**create_dummy_map(t_map *map)
{
	char	**new_map;
	int		i;
	int		j;
	char	*temp;

	new_map = (char **)malloc(sizeof(char *) * 
			map->map_x_lenght * map->map_y_lenght);
	i = 0;
	while (map->map[i])
	{
		j = 0;
		temp = (char *)malloc(sizeof(char) * ft_strlen2(map->map[i]));
		while (map->map[i][j])
		{
			temp[j] = map->map[i][j];
			j++;
		}
		new_map[i] = temp;
		i++;
	}
	return (new_map);
}

static void	is_player_reach_all_collectiables(
	char **map, int i, int j, int *coins)
{
	if (map[i][j] == '1' || map[i][j] == 'E')
		return ;
	if (map[i][j] == 'C')
	{
		*coins += 1;
	}
	map[i][j] = '1';
	is_player_reach_all_collectiables(map, i + 1, j, coins);
	is_player_reach_all_collectiables(map, i - 1, j, coins);
	is_player_reach_all_collectiables(map, i, j + 1, coins);
	is_player_reach_all_collectiables(map, i, j - 1, coins);
}

static void	is_there_all_things(t_map *map)
{
	if (!(map->coin > 0 && map->player.x && map->exit.x))
		error_massage("Not Enough Things In The Map", map->map);
}

static void	found_things(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'E')
	{
		map->exit.x = j;
		map->exit.y = i;
	}
	else if (map->map[i][j] == 'C')
		map->coin++;
	else if (map->map[i][j] == 'P')
	{
		map->player.x = j;
		map->player.y = i;
	}
	else if (map->map[i][j] != '1' && map->map[i][j] != '0')
		error_massage("Invalid Map Character", map->map);
}

void	calculate_things(t_map *map)
{
	int	i;
	int	j;
	int	coins;

	i = 0;
	map->coin = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			found_things(map, i, j);
			j++;
		}
		i++;
	}
	is_there_all_things(map);
	map->map_x_lenght = j;
	map->map_y_lenght = i;
	coins = 0;
	is_player_reach_all_collectiables(
		create_dummy_map(map), map->player.y, map->player.x, &coins);
	if (coins != map->coin)
		error_massage("Player Can not Collect All Coins", map->map);
}

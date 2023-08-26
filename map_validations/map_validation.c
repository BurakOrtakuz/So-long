/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 00:02:05 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/26 11:33:55 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../utils/get_next_line/get_next_line.h"
#include <stdio.h>

static int	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'r' && str[i - 2] == 'e' && 
		str[i - 3] == 'b' && str[i - 4] == '.')
		return (1);
	return (0);
}

void	error_massage(char *str, char **map)
{
	ft_putstr("Error\n", 1);
	ft_putstr(str, 1);
	if (map)
		free(map);
	exit(-1);
}

char	**is_file_valid(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		error_massage("Invalid number of arguman!", NULL);
	if (!check_ber(av[1]))
		error_massage("Invalid file type!", NULL);
	fd = open(av[1], O_RDONLY);
	if (!fd)
	{
		close(fd);
		error_massage("FIle read failed", NULL);
	}
	return (is_valid(fd));
}

char	**is_valid(int fd)
{
	char	**map;
	char	*temp;
	char	*temp2;
	int		i;
	int		j;

	temp2 = "\0";
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		i = ft_strlen2(temp2);
		temp2 = ft_realloc(temp2, i + ft_strlen2(temp));
		j = 0;
		while (j < ft_strlen2(temp))
		{
			temp2[i + j] = temp[j];
			j++;
		}
	}
	map = ft_split(temp2, '\n');
	is_map_borders_valid(map);
	return (map);
}

void	is_map_borders_valid(char **map)
{
	int	i;
	int	j;
	int	lenght;

	i = 0;
	j = 0;
	lenght = ft_strlen2(map[0]);
	while (map[i])
	{
		if (lenght != ft_strlen2(map[i]))
			error_massage("Invalid Map Lenght", map);
		if (map[i][0] != '1' || map[i][lenght - 1] != '1')
			error_massage("Invalid Map Border", map);
		i++;
	}
	while (j < lenght) 
	{
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			error_massage("Invalid Map Border", map);
		j++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:57:10 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/25 17:58:36 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int fd)
{
	write(fd, str, ft_strlen2(str));
}

void	*ft_memcpy(char *dst, const char *src, int n)
{
	int	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_realloc(char *src, int size)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(size * sizeof(char));
	while (src[i])
	{
		temp[i] = src[i];
		i++;
	}
	return (temp);
}

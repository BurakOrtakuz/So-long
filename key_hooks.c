/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bortakuz <bortakuz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:45:10 by bortakuz          #+#    #+#             */
/*   Updated: 2023/08/27 11:08:31 by bortakuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_variables.h"
#include "so_long.h"
#include "./minilibx/mlx.h"

void	set_key_hooks(t_program *program, t_map *map)
{
	mlx_key_hook();
}

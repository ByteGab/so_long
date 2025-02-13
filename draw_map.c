/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:31:42 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/13 16:46:18 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(char *map, t_vars *vars)
{
	int i;

	i = 0;
	if (map[i] == '0')
	{
		// draw background
	}
	else if (map[i] == '1')
	{
		// draw wall
	}
	else if (map[i] == 'P')
	{
		// if character is 1
		// draw Character
		// else more character is error
	}
	else if (map[i] == 'C')
	{
		// draw coins
		// count to coins
	}
	else if (map[i] == 'E')
	{
		// if exit is 1
		// draw Exit when recolect total Coins
		// else more exits is error
	}
}
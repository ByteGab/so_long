/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:31:42 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 19:08:14 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_items(t_vars *vars)
{
	if (vars->count_coins == 0)
		error_item(vars);
	if (vars->count_exit == 0 || vars->count_exit > 1)
		error_item(vars);
	if (vars->count_player == 0 || vars->count_player > 1)
		error_item(vars);
}

void	put_img_and_count(char item, t_vars *vars, int i, int j)
{
	if (item == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player, j * 64, i
			* 64);
	else if (item == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->background, j * 64,
			i * 64);
	else if (item == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->walls, j * 64, i
			* 64);
	else if (item == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->coins, j * 64, i
			* 64);
	else if (item == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, j * 64, i
			* 64);
}

void	put_img(char item, t_vars *vars, int i, int j)
{
	if (item == 'P')
	{
		vars->pos_x = j * 64;
		vars->pos_y = i * 64;
		vars->count_player++;
	}
	else if (item == 'C')
		vars->count_coins++;
	else if (item == 'E')
		vars->count_exit++;
	else if (item != '0' && item != '1' && item != 'E' && item != 'C'
		&& item != 'P')
		error_item(vars);
	put_img_and_count(item, vars, i, j);
}

void	place_textures(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->rows)
	{
		j = 0;
		while (j < vars->columns)
		{
			put_img(vars->map[i][j], vars, i, j);
			j++;
		}
		i++;
	}
	check_items(vars);
}

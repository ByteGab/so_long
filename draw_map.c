/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:31:42 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 03:41:59 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_textures(t_vars *vars)
{
	int	img_width;
	int	img_height;
	int	i;
	int	j;

	i = 0;
	vars->background = mlx_xpm_file_to_image(vars->mlx, "assets/Grass.xpm",
			&img_width, &img_height);
	vars->walls = mlx_xpm_file_to_image(vars->mlx, "assets/water.xpm",
			&img_width, &img_height);
	vars->player = mlx_xpm_file_to_image(vars->mlx, "assets/Dino.xpm",
			&img_width, &img_height);
	vars->player_move = mlx_xpm_file_to_image(vars->mlx, "assets/Dino_move.xpm",
			&img_width, &img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "assets/House.xpm",
			&img_width, &img_height);
	vars->coins = mlx_xpm_file_to_image(vars->mlx, "assets/Egg.xpm", &img_width,
			&img_height);
	vars->count_coins = 0;
	vars->count_moves = 0;
	vars->count_exit = 0;
	vars->count_player = 0;
	while (i < vars->rows)
	{
		j = 0;
		while (j < vars->columns)
		{
			if (vars->map[i][j] != 'P' && vars->map[i][j] != '0'
				&& vars->map[i][j] != '1' && vars->map[i][j] != 'C'
				&& vars->map[i][j] != 'E')
			{
				printf("El mapa no es valido");
				mlx_destroy_window(vars->mlx, vars->win);
				exit(0);
			}
			else if (vars->map[i][j] == 'P')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player, j
					* 64, i * 64);
				vars->pos_x = j * 64;
				vars->pos_y = i * 64;
				vars->count_player++;
			}
			else if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
					j * 64, i * 64);
			else if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->walls, j
					* 64, i * 64);
			else if (vars->map[i][j] == 'C')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->coins, j
					* 64, i * 64);
				vars->count_coins++;
			}
			else if (vars->map[i][j] == 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, j
					* 64, i * 64);
				vars->count_exit++;
			}
			j++;
		}
		i++;
	}
	// not coins
	if (vars->count_coins == 0)
	{
		printf("El mapa no es valido");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	// error exit
	if (vars->count_exit == 0 || vars->count_exit > 1)
	{
		printf("El mapa no es valido");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	// error player
	if (vars->count_player == 0 || vars->count_player > 1)
	{
		printf("El mapa no es valido");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}

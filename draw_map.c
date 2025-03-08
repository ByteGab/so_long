/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:31:42 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/08 17:45:48 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void place_textures(t_vars *vars)
{
    int img_width;
    int img_height;
	int i;
	int j;

	i = 0;
    vars->background = mlx_xpm_file_to_image(vars->mlx, "assets/Grass.xpm", &img_width, &img_height);
    vars->walls = mlx_xpm_file_to_image(vars->mlx, "assets/water.xpm", &img_width, &img_height);
	vars->player = mlx_xpm_file_to_image(vars->mlx, "assets/Dino.xpm", &img_width, &img_height);
	vars->player_move = mlx_xpm_file_to_image(vars->mlx, "assets/Dino_move.xpm", &img_width, &img_height);
    vars->exit = mlx_xpm_file_to_image(vars->mlx, "assets/House.xpm", &img_width, &img_height);
    vars->coins = mlx_xpm_file_to_image(vars->mlx, "assets/Egg.xpm", &img_width, &img_height);
	while (i < vars->rows)
	{
		j = 0;
		while (j < vars->columns)
		{
			if (vars->map[i][j] == 'P')
			{
				 mlx_put_image_to_window(vars->mlx, vars->win, vars->player, j * 64, i * 64);
				vars->pos_x = j * 64;
                vars->pos_y = i * 64;
			}
            else if (vars->map[i][j] == '0')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->background, j * 64, i * 64);
            else if (vars->map[i][j] == '1')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->walls, j * 64, i * 64);
            else if (vars->map[i][j] == 'C')
                mlx_put_image_to_window(vars->mlx, vars->win, vars->coins, j * 64, i * 64);
            else if (vars->map[i][j] == 'E')
            	mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, j * 64, i * 64);
			j++;
		}
		printf("%d\n",j);
		i++;
	}
	printf("%d\n",i);
}

// void	draw_map(char *map, t_vars *vars)
// {
// 	int i;

// 	i = 0;
// 	if (map[i] == '0')
// 	{
// 		// draw background
// 	}
// 	else if (map[i] == '1')
// 	{
// 		// draw wall
// 	}
// 	else if (map[i] == 'P')
// 	{
// 		// if character is 1
// 		// draw Character
// 		// else more character is error
// 	}
// 	else if (map[i] == 'C')
// 	{
// 		// draw coins
// 		// count to coins
// 	}
// 	else if (map[i] == 'E')
// 	{
// 		// if exit is 1
// 		// draw Exit when recolect total Coins
// 		// else more exits is error
// 	}
// }
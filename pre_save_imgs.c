/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_save_imgs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:37:13 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 21:27:29 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_count(t_vars *vars)
{
	vars->count_coins = 0;
	vars->count_moves = 0;
	vars->count_exit = 0;
	vars->count_player = 0;
	vars->moves = 0;
}

void	pre_save_imgs(t_vars *vars)
{
	int	img_width;
	int	img_height;

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
	start_count(vars);
}

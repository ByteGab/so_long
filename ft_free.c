/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 04:37:07 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 21:34:01 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up_imgs(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->background);
	mlx_destroy_image(vars->mlx, vars->walls);
	mlx_destroy_image(vars->mlx, vars->player);
	mlx_destroy_image(vars->mlx, vars->player_move);
	mlx_destroy_image(vars->mlx, vars->exit);
	mlx_destroy_image(vars->mlx, vars->coins);
}

void	clean_up_map(t_vars *vars)
{
	int	i;

	if (!vars || !vars->map)
		return ;
	i = 0;
	while (i < vars->rows)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	vars->map = NULL;
}

void	clean_up_all(t_vars *vars)
{
	clean_up_imgs(vars);
	clean_up_map(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

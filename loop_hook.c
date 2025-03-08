/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:14 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/08 22:49:42 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		printf("Close Window\n");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 119 || keycode == 65362)
	{
		// check if wall || exit
		if (vars->map[(vars->pos_y / 64) - 1][vars->pos_x / 64] != '1')
		{
			// if exit is posible?
			if (vars->map[(vars->pos_y / 64) - 1][vars->pos_x / 64] == 'E'
				&& vars->count_coins == 0)
			{
				mlx_destroy_window(vars->mlx, vars->win);
				exit(0);
			}
			else if (vars->map[(vars->pos_y / 64) - 1][vars->pos_x / 64] != 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
					vars->pos_x, vars->pos_y);
				vars->pos_y -= 64;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
					vars->pos_x, vars->pos_y);
			}
		}
		// recolect coin
		if (vars->map[vars->pos_y / 64][(vars->pos_x / 64)] == 'C')
		{
			vars->count_coins--;
			vars->map[vars->pos_y / 64][(vars->pos_x / 64)] = '0';
			printf("Quedan: %d\n", vars->count_coins);
		}
	}
	else if (keycode == 115 || keycode == 65364)
	{
		// check if wall || exit
		if (vars->map[(vars->pos_y / 64) + 1][vars->pos_x / 64] != '1')
		{
			// if exit is posible?
			if (vars->map[(vars->pos_y / 64) + 1][vars->pos_x / 64] == 'E'
				&& vars->count_coins == 0)
			{
				mlx_destroy_window(vars->mlx, vars->win);
				exit(0);
			}
			else if (vars->map[(vars->pos_y / 64) + 1][vars->pos_x / 64] != 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
					vars->pos_x, vars->pos_y);
				vars->pos_y += 64;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
					vars->pos_x, vars->pos_y);
			}
		}
		// // recolect coin
		if (vars->map[vars->pos_y / 64][(vars->pos_x / 64)] == 'C')
		{
			vars->count_coins--;
			vars->map[vars->pos_y / 64][(vars->pos_x / 64)] = '0';
			printf("Quedan: %d\n", vars->count_coins);
		}
	}
	else if (keycode == 97 || keycode == 65361)
	{
		// check if wall || exit
		if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) - 1] != '1')
		{
			// if exit is posible?
			if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) - 1] == 'E'
				&& vars->count_coins == 0)
			{
				mlx_destroy_window(vars->mlx, vars->win);
				exit(0);
			}
			else if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) - 1] != 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
					vars->pos_x, vars->pos_y);
				vars->pos_x -= 64;
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
					vars->pos_x, vars->pos_y);
			}
		}
		// recolect coin
		if (vars->map[vars->pos_y / 64][(vars->pos_x / 64)] == 'C')
		{
			vars->count_coins--;
			vars->map[vars->pos_y / 64][(vars->pos_x / 64)] = '0';
			printf("Quedan: %d\n", vars->count_coins);
		}
	}
	else if (keycode == 100 || keycode == 65363)
	{
		static int toggle = 0;

		// check if wall || exit
		if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) + 1] != '1')
		{
			// if exit is posible?
			if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) + 1] == 'E'
				&& vars->count_coins == 0)
			{
				mlx_destroy_window(vars->mlx, vars->win);
				exit(0);
			}
			else if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) + 1] != 'E')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
					vars->pos_x, vars->pos_y);
				vars->pos_x += 64;

				if (toggle % 2 == 0)
					mlx_put_image_to_window(vars->mlx, vars->win,
						vars->player_move, vars->pos_x, vars->pos_y);
				else
					mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
						vars->pos_x, vars->pos_y);
				toggle++;
			}
		}
		// recolect coin
		if (vars->map[vars->pos_y / 64][(vars->pos_x / 64)] == 'C')
		{
			vars->count_coins--;
			vars->map[vars->pos_y / 64][(vars->pos_x / 64)] = '0';
			printf("Quedan: %d\n", vars->count_coins);
		}
	}
	return (0);
}
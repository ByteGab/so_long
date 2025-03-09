/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:14 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 19:03:51 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_w(t_vars *vars)
{
	print_moves(vars);
	if (vars->map[(vars->pos_y / 64) - 1][vars->pos_x / 64] != '1')
	{
		if (vars->map[(vars->pos_y / 64) - 1][vars->pos_x / 64] == 'E'
			&& vars->count_coins == 0)
			error_moves(vars);
		else if (vars->map[(vars->pos_y / 64) - 1][vars->pos_x / 64] != 'E')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
				vars->pos_x, vars->pos_y);
			vars->pos_y -= 64;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
				vars->pos_x, vars->pos_y);
		}
	}
	if (vars->map[vars->pos_y / 64][(vars->pos_x / 64)] == 'C')
	{
		vars->count_coins--;
		vars->map[vars->pos_y / 64][(vars->pos_x / 64)] = '0';
	}
}

void	key_s(t_vars *vars)
{
	print_moves(vars);
	if (vars->map[(vars->pos_y / 64) + 1][vars->pos_x / 64] != '1')
	{
		if (vars->map[(vars->pos_y / 64) + 1][vars->pos_x / 64] == 'E'
			&& vars->count_coins == 0)
			error_moves(vars);
		else if (vars->map[(vars->pos_y / 64) + 1][vars->pos_x / 64] != 'E')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
				vars->pos_x, vars->pos_y);
			vars->pos_y += 64;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
				vars->pos_x, vars->pos_y);
		}
	}
	if (vars->map[vars->pos_y / 64][(vars->pos_x / 64)] == 'C')
	{
		vars->count_coins--;
		vars->map[vars->pos_y / 64][(vars->pos_x / 64)] = '0';
	}
}

void	key_a(t_vars *vars)
{
	print_moves(vars);
	if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) - 1] != '1')
	{
		if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) - 1] == 'E'
			&& vars->count_coins == 0)
			error_moves(vars);
		else if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) - 1] != 'E')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
				vars->pos_x, vars->pos_y);
			vars->pos_x -= 64;
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
				vars->pos_x, vars->pos_y);
		}
	}
	if (vars->map[vars->pos_y / 64][(vars->pos_x / 64)] == 'C')
	{
		vars->count_coins--;
		vars->map[vars->pos_y / 64][(vars->pos_x / 64)] = '0';
	}
}

void	key_d(t_vars *vars)
{
	print_moves(vars);
	if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) + 1] != '1')
	{
		if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) + 1] == 'E'
			&& vars->count_coins == 0)
			error_moves(vars);
		else if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) + 1] != 'E')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->background,
				vars->pos_x, vars->pos_y);
			vars->pos_x += 64;
			if (vars->moves % 2 == 0)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player_move,
					vars->pos_x, vars->pos_y);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player,
					vars->pos_x, vars->pos_y);
			vars->moves++;
		}
	}
	if (vars->map[vars->pos_y / 64][(vars->pos_x / 64)] == 'C')
	{
		vars->count_coins--;
		vars->map[vars->pos_y / 64][(vars->pos_x / 64)] = '0';
	}
}

int	loop_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		error_moves(vars);
	else if (keycode == 119 || keycode == 65362)
		key_w(vars);
	else if (keycode == 115 || keycode == 65364)
		key_s(vars);
	else if (keycode == 97 || keycode == 65361)
		key_a(vars);
	else if (keycode == 100 || keycode == 65363)
		key_d(vars);
	return (0);
}

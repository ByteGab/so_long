/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:14 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/07 00:15:08 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int loop_hook(int keycode, t_vars *vars)
{
    if (keycode == 65307)
    {
        printf("Close Window\n");
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    else if (keycode == 119) // W key
    {
        if (vars->map[(vars->pos_y / 64) - 1][vars->pos_x / 64] != '1') // Check if next position is not a wall
        {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->background, vars->pos_x, vars->pos_y);
            vars->pos_y -= 64;
            mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, vars->pos_y);
        }
    }
    else if (keycode == 115) // S key
    {
        if (vars->map[(vars->pos_y / 64) + 1][vars->pos_x / 64] != '1') // Check if next position is not a wall
        {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->background, vars->pos_x, vars->pos_y);
            vars->pos_y += 64;
            mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, vars->pos_y);
        }
    }
    else if (keycode == 97) // A key
    {
        if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) - 1] != '1') // Check if next position is not a wall
        {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->background, vars->pos_x, vars->pos_y);
            vars->pos_x -= 64;
            mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, vars->pos_y);
        }
    }
    else if (keycode == 100) // D key
    {
        if (vars->map[vars->pos_y / 64][(vars->pos_x / 64) + 1] != '1') // Check if next position is not a wall
        {
            mlx_put_image_to_window(vars->mlx, vars->win, vars->background, vars->pos_x, vars->pos_y);
            vars->pos_x += 64;
            mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, vars->pos_y);
        }
    }
    return (0);
}
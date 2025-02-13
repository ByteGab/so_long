/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:14 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/13 18:11:41 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	loop_hook(int keycode, t_vars *vars)
{

    if (keycode == 65307)
    {
        printf("Close Window\n");
        exit(0);
        mlx_destroy_window(vars, vars);
    }
    else if (keycode == 119)
    {
        printf("Key W\n");
        mlx_put_image_to_window(vars->mlx, vars->win, vars->walls, vars->pos_x, vars->pos_y);
        vars->pos_y -= 64;
        mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, vars->pos_y);
    }
    else if (keycode == 115)
    {
        printf("Key S\n");
        mlx_put_image_to_window(vars->mlx, vars->win, vars->walls, vars->pos_x, vars->pos_y);
        vars->pos_y += 64;
        mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, vars->pos_y);
    }
    else if (keycode == 97)
    {
        printf("key A\n");
        mlx_put_image_to_window(vars->mlx, vars->win, vars->walls, vars->pos_x, vars->pos_y);
        vars->pos_x -= 64;
        // mlx_put_image_to_window(vars->mlx, vars->win, vars->player_move, vars->pos_x, vars->pos_y);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, vars->pos_y);
    }
    else if (keycode == 100)
    {
        printf("Key D\n");
        mlx_put_image_to_window(vars->mlx, vars->win, vars->walls, vars->pos_x, vars->pos_y);
        vars->pos_x += 64;
        mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, vars->pos_y);
    }
    // void *temp;
    // if (vars->flag == 0)
    // {
    //     temp = vars->player;
    //     vars->player = vars->player_move;
    //     vars->flag = 1;
    // }
    // else if (vars->flag == 1)
    // {
    //         vars->player = temp;
    //         vars->flag = 0;
    // }
    
    return (0);
}
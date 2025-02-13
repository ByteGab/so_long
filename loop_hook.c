/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:14 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/13 14:08:26 by gafreire         ###   ########.fr       */
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
        mlx_put_image_to_window(vars->mlx, vars->win, vars->walls, vars->pos_x, 200);
        vars->pos_x += 64;
        mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, 200);
    }
    else if (keycode == 115)
    {
        printf("Key S\n");
        mlx_put_image_to_window(vars->mlx, vars->win, vars->walls, vars->pos_x, 200);
        vars->pos_x -= 64;
        mlx_put_image_to_window(vars->mlx, vars->win, vars->player, vars->pos_x, 200);
    }
    else if (keycode == 97)
    {
        printf("key A\n");
        // vars->player.pos.y -= 1;
    }
    else if (keycode == 100)
    {
        printf("Key D\n");
        // vars->player.pos.y += 1;
    }
    return (0);
}

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, loop_hook, &vars);

// 	mlx_loop(vars.mlx);
// }
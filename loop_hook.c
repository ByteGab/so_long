/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:14 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/01 22:02:42 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
    if (keycode == 65307)
    {
        printf("Close Window\n");
        mlx_destroy_window(vars, vars);
        exit(0);
    }
    else if (keycode == 119)
    {
        printf("Key W\n");
        // vars->player.pos.x += 1;
    }
    else if (keycode == 115)
    {
        printf("Key S\n");
        // vars->player.pos.x -= 1;
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

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);

	mlx_loop(vars.mlx);
}
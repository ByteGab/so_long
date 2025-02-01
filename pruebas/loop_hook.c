#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
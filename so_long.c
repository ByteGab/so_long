/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:03 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/07 01:10:48 by gafreire         ###   ########.fr       */
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
    vars->background = mlx_xpm_file_to_image(vars->mlx, "assets/4b_64x64.xpm", &img_width, &img_height);
    vars->walls = mlx_xpm_file_to_image(vars->mlx, "assets/4b_64x64.xpm", &img_width, &img_height);
	vars->player = mlx_xpm_file_to_image(vars->mlx, "assets/Dino_with_background.xpm", &img_width, &img_height);
    //vars->exit = mlx_xpm_file_to_image(vars->mlx, "assets/exit.xpm", &img_width, &img_height);
    //vars->coins = mlx_xpm_file_to_image(vars->mlx, "assets/Dino_with_background.xpm", &img_width, &img_height);
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
            // else if (data->map[i][j] == 'C')
            //     mlx_put_image_to_window(vars->mlx, vars->win, vars->coins, j * 64, i * 64);
            // else if (data->map[i][j] == 'E')
            //     mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, j * 64, i * 64);
			j++;
		}
		printf("%d\n",j);
		i++;
	}
	printf("%d\n",i);
}
int	main(int argc, char *argv[])
{
	t_vars vars;
	t_map map_data;

	// comprobate map
	map_data.check = check_map(argc,&map_data,argv[1],&vars);
	// read_map
	if (map_data.check == 1)
	{
		print_map(&vars);
		// init mlx
		vars.mlx = mlx_init();
		vars.size_x = vars.columns * 64;
		vars.size_y = vars.rows * 64;
		// create window
		vars.win = mlx_new_window(vars.mlx, vars.size_x, vars.size_y, "Paparoni esto es easy");
		// open window
		printf("Created Window\n");
		// show images
		place_textures(&vars);		
		// loop_hook && close window
		mlx_key_hook(vars.win, loop_hook, &vars);
		mlx_hook(vars.win, 17, 0, close_window, &vars);
		mlx_loop(vars.mlx);
		printf("Esto es:%d\n",vars.pos_x);
		// finish loop
		mlx_loop(vars.mlx);
		// free all
		//  cc -D SIZE_X=800 -D SIZE_Y=800 so_long.c read_map.c loop_hook.c close_window.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c check_map.c libmlx_Linux.a -lX11 -lXext -o game
	}
	return (0);
}
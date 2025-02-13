/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:03 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/13 16:17:15 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_vars vars;
	// img
	void *background_img;
	void *wall;
	void *img2;
	char *relative_path_background = "assets/Background.xpm";
	char *relative_path2 = "assets/4b_64x64.xpm";
	char *character1 = "assets/Dino_with_background.xpm";
	char *character2 = "assets/DinoMove_with_background.xpm";
	int img_width;
	int img_height;
	int img_width2;
	int img_height2;
	int img_width3;
	int img_height3;
	int img_width4;
	int img_height4;
	int i;
	int z;

	i = 60;

	if (argc == 1)
		printf("Error añade un mapa\n");
	else
	{
		// key handler

		vars.mlx = mlx_init();
		// read_map
		
		vars.win = mlx_new_window(vars.mlx, SIZE_X, SIZE_Y, "Paparoni esto es easy");
		// open window
		printf("Created Window\n");
		// show images		
		// background
		background_img = mlx_xpm_file_to_image(vars.mlx,
				relative_path_background, &img_width, &img_height);
		mlx_put_image_to_window(vars.mlx, vars.win, background_img, 0, 0);
		printf("Created Background\n");
		// walls
		wall = mlx_xpm_file_to_image(vars.mlx, relative_path2, &img_width2,&img_height2);
		if (wall == NULL)
		{
			printf("Imagen vacia");
		}
		vars.walls = wall;
		read_map(argv[1], &vars);
		// mlx_put_image_to_window(vars.mlx, vars.win, vars.walls, 1, 1);
		img2 = mlx_xpm_file_to_image(vars.mlx, relative_path2, &img_width2,
				&img_height2);
		vars.player = mlx_xpm_file_to_image(vars.mlx, character1, &img_width3,
				&img_height3);
		vars.player_move = mlx_xpm_file_to_image(vars.mlx, character2, &img_width4,
				&img_height4);
		mlx_put_image_to_window(vars.mlx, vars.win, img2, 1, 1);
		int x = 0;
		mlx_put_image_to_window(vars.mlx, vars.win, vars.player, vars.pos_x, vars.pos_y);
		// print manual walls
		i = 0;
		while (i < SIZE_X && i < SIZE_Y)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, img2, (i * 64), 1);
			mlx_put_image_to_window(vars.mlx, vars.win, img2, 1, (i * 64));
			mlx_put_image_to_window(vars.mlx, vars.win, img2, (i * 64), SIZE_Y - 64);
			mlx_put_image_to_window(vars.mlx, vars.win, img2, SIZE_X - 64, (i * 64));
			i++;
		}
		z = 0;
		// while (z < SIZE_X && z < SIZE_Y)
		// {
		// 	mlx_put_image_to_window(vars.mlx, vars.win, img2, (z * 16), 2);
		// 	mlx_put_image_to_window(vars.mlx, vars.win, img2, 2, (z * 16));
		// 	mlx_put_image_to_window(vars.mlx, vars.win, img2, (z * 16), SIZE_Y - 16);
		// 	mlx_put_image_to_window(vars.mlx, vars.win, img2, SIZE_X - 16, (z * 16));
		// 	z++;
		// }
		printf("Created walls\n");
		// loop_hook && close window
		mlx_key_hook(vars.win, loop_hook, &vars);
		mlx_loop(vars.mlx);
		printf("Esto es:%d\n",vars.pos_x);
		// finish loop
		mlx_loop(vars.mlx);
		//  cc game.c libmlx_Linux.a -lX11 -lXext -o game
	}
	return (0);
}
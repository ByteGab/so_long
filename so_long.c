/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:03 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/10 13:48:19 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_vars vars;
	// img
	void *background_img;
	void *img2;
	char *relative_path_background = "assets/Background.xpm";
	char *relative_path2 = "assets/4b.xpm";
	int img_width;
	int img_height;
	int img_width2;
	int img_height2;
	int i;
	int z;

	i = 60;

	if (argc == 1)
		printf("Error añada un mapa\n");
	else
	{
		// read_map
		read_map(argv[1]);
		// key handler

		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 928, 793, "Paparoni esto es easy");
		// open window
		printf("Created Window\n");
		// show images
		// background
		background_img = mlx_xpm_file_to_image(vars.mlx,
				relative_path_background, &img_width, &img_height);
		mlx_put_image_to_window(vars.mlx, vars.win, background_img, 0, 0);
		printf("Created Background\n");
		// loo_hook
		mlx_key_hook(vars.win, loop_hook, &vars);
		mlx_loop(vars.mlx);
		// walls
		img2 = mlx_xpm_file_to_image(vars.mlx, relative_path2, &img_width2,
				&img_height2);
		mlx_put_image_to_window(vars.mlx, vars.win, img2, 1, 1);
		while (i > 0)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, img2, (i * 16), 1);
			i--;
		}
		printf("Created walls\n");
		// close window
		mlx_key_hook(vars.win, close_window, vars.win);

		// finish loop
		mlx_loop(vars.mlx);
		//  cc game.c libmlx_Linux.a -lX11 -lXext -o game
	}
	return (0);
}
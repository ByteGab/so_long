/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:03 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/07 13:31:13 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
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
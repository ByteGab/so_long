/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:03 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 05:16:04 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_map	map_data;

	map_data.check = check_map(argc, &map_data, argv[1], &vars);
	if (map_data.check == 1)
	{
		vars.mlx = mlx_init();
		vars.size_x = vars.columns * 64;
		vars.size_y = vars.rows * 64;
		vars.win = mlx_new_window(vars.mlx, vars.size_x, vars.size_y,
				"so_long");
		place_textures(&vars);
		mlx_key_hook(vars.win, loop_hook, &vars);
		mlx_hook(vars.win, 17, 0, close_window, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}

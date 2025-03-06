/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:56 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/06 16:10:22 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef SIZE_X
#  define SIZE_X 1024
# endif
# ifndef SIZE_Y
#  define SIZE_Y 900
# endif
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*walls;
	char	*background;
	void	*player;
	void	*player_move;
	int		pos_x;
	int		pos_y;
}			t_vars;

typedef struct s_map
{
	int		lines;
	int		check_rectangular;
	int		check_walls;
	int		check_exit;
	int		check_player;
	int		check_coins;
	int 	check;
}			t_map;

void		read_map(char *map, t_vars *vars);
int			loop_hook(int keycode, t_vars *vars);
int			close_window(int keycode, void *param);
void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int check_map(int maps,t_map *map_data,char *map,t_vars *vars);

#endif
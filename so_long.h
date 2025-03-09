/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:56 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 03:35:46 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*walls;
	void	*background;
	void	*player;
	void	*coins;
	void	*exit;
	void	*player_move;
	int		pos_x;
	int		pos_y;
	int		size_x;
	int		size_y;
	char	**map;
	int		rows;
	int		columns;
	int		count_coins;
	int		count_moves;
	int		count_exit;
	int		count_player;
}			t_vars;

typedef struct s_map
{
	int		lines;
	int		check_rectangular;
	int		check_walls;
	int		check_exit;
	int		check_player;
	int		check_coins;
	int		check;
}			t_map;

void		read_map(char *argv, t_vars *vars);
int			loop_hook(int keycode, t_vars *vars);
int			close_window(t_vars *vars);
int			check_map(int maps, t_map *map_data, char *map, t_vars *vars);
void		place_textures(t_vars *vars);

#endif
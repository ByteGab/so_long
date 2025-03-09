/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:56 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 21:26:40 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
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
	int		moves;
}			t_vars;

void		read_map(char *argv, t_vars *vars);
int			loop_hook(int keycode, t_vars *vars);
int			close_window(t_vars *vars);
void		check_map(int maps, char *map, t_vars *vars);
void		place_textures(t_vars *vars);
void		clean_up_all(t_vars *vars);
void		clean_up_map(t_vars *vars);
void		clean_up_imgs(t_vars *vars);
void		pre_save_imgs(t_vars *vars);
void		error_item(t_vars *vars);
void		error_moves(t_vars *vars);
void		print_moves(t_vars *vars);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:43:56 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/02 16:20:19 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GAME_H
# define GAME_H

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line/get_next_line.h"

void read_map();
int close_window(int keycode, void *param);


#endif
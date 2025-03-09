/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 04:37:07 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 05:04:05 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void clean_up(t_vars *vars) {
    if (vars->coins) {
        mlx_destroy_image(vars->mlx, vars->coins);
        vars->coins = NULL; // Evitar doble liberación
    }
    if (vars->exit) {
        mlx_destroy_image(vars->mlx, vars->exit);
        vars->exit = NULL; // Evitar doble liberación
    }
    if (vars->player_move) {
        mlx_destroy_image(vars->mlx, vars->player_move);
        vars->player_move = NULL; // Evitar doble liberación
    }
    if (vars->player) {
        mlx_destroy_image(vars->mlx, vars->player);
        vars->player = NULL; // Evitar doble liberación
    }
    if (vars->walls) {
        mlx_destroy_image(vars->mlx, vars->walls);
        vars->walls = NULL; // Evitar doble liberación
    }
    if (vars->background) {
        mlx_destroy_image(vars->mlx, vars->background);
        vars->background = NULL; // Evitar doble liberación
    }
    if (vars->win) {
        mlx_destroy_window(vars->mlx, vars->win);
        vars->win = NULL; // Evitar doble liberación
    }
    if (vars->mlx) {
        free(vars->mlx); // Libera el puntero mlx si es necesario
        vars->mlx = NULL; // Evitar doble liberación
    }
}

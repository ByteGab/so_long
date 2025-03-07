/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:10:56 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/07 00:51:03 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_vars *vars)
{
    printf("Close Window\n");
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    return (0);
}
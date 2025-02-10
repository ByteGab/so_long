/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:10:56 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/10 13:48:50 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(int keycode, void *param)
{
    if (keycode == 65307)
    {
        printf("Close Window\n");
        mlx_destroy_window(param, param);
        exit(0);
    }
    return (0);
}
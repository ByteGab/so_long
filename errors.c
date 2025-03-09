/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:40:59 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 21:30:15 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_vars *vars)
{
	vars->count_moves++;
	ft_printf("\033[0;32mLlevas: %d movimientos\033[0m\n", vars->count_moves);
}

void	error_item(t_vars *vars)
{
	ft_printf("\033[0;31mEl mapa no contiene items validos\033[0m");
	clean_up_all(vars);
	exit(EXIT_FAILURE);
}

void	error_moves(t_vars *vars)
{
	clean_up_all(vars);
	exit(EXIT_FAILURE);
}

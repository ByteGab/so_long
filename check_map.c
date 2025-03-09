/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:56:28 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 03:52:22 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_file(void)
{
	printf("\033[0;31mEl mapa no es valido\033[0m");
	exit(0);
}
void	check_file(char *file)
{
	size_t	size;
	char	*type_file;
	size_t	i;
	int		j;

	size = ft_strlen(file);
	type_file = ".ber";
	i = size;
	j = 0;
	if (size < 4)
		error_file();
	while (i > 0)
	{
		if (file[i] == '.')
			break ;
		i--;
	}
	if ((size - i) != 4)
		error_file();
	while (file[i] != '\0' && type_file[j] != '\0')
	{
		if (file[i] != type_file[j])
			error_file();
		i++;
		j++;
	}
}
int	is_rectangular(char **map, int rows)
{
	int		i;
	size_t	length;

	i = 0;
	if (rows == 0 || map == NULL)
	{
		return (0);
	}
	length = ft_strlen(map[0]);
	while (i < rows)
	{
		if (ft_strlen(map[i]) != length)
		{
			return (0); // No es rectangular
		}
		i++;
	}
	return (1);
}
int	check_map(int maps, t_map *map_data, char *map, t_vars *vars)
{
	if (maps != 2)
	{
		if (maps == 1)
			printf("Error añade un mapa\n");
		else
			printf("Error añade un solo mapa\n");
		exit(0);
	}
	check_file(map);
	read_map(map, vars);
	// map is rectangular ?
	if (!is_rectangular(vars->map, vars->rows))
		error_file();
	map_data->check_walls = 0;
	if (map_data->check_walls == 1)
	{
		printf("Error el mapa no esta cerrado por paredes\n");
		return (0);
	}
	map_data->check_exit = 0;
	if (map_data->check_exit == 1)
	{
		printf("Error el mapa no tiene una salida correcta\n");
		return (0);
	}
	map_data->check_player = 0;
	if (map_data->check_player == 1)
	{
		printf("Error el mapa no tiene una posición inicial correcta\n");
		return (0);
	}
	map_data->check_coins = 0;
	if (map_data->check_coins == 1)
	{
		printf("Error el mapa no tiene al menos una coleccionable\n");
		return (0);
	}
	else
	{
		return (1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:41:44 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/05 21:40:14 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// #include <string.h> // borrar

void	read_map(char *map, t_vars *vars)
{
	int fd;
	char *line;
	int columns;
	char **file_map;
	t_map map_data;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	columns = 0;
	map_data.rectangular = 1;

	file_map = (char **)malloc(strlen(line) - 1);
	// malloc para el doble puntero 
	// malloc para cada puntero dentro del doble
	while (line != NULL)
	{
		// file_map[columns] = strdup(line);
		printf("%s", line);
		free(line);
		// free(file);
		columns++;
		line = get_next_line(fd);
	}
	// int i;

	// i = 0;
	// while (columns > 0)
	// {
	// 	while (file_map[columns][i] != '\0')
	// 	{
	// 		write(1,&file_map[columns][i],1);
	// 		i++;
	// 	}
	// 	columns--;
	// }
	
	printf("\n");
	// printf("%d\n",columns);
	close(fd);
}
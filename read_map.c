/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:41:44 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/13 19:57:08 by gafreire         ###   ########.fr       */
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

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	columns = 0;

	file_map = (char **)malloc(strlen(line) - 1);
	// malloc para el doble puntero 
	// malloc para cada puntero dentro del doble
	while (line != NULL)
	{
		// file_map[columns] = strdup(line);
		printf("%s", line);
		free(line);
		printf("\n");
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
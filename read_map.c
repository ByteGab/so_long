/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:41:44 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/12 13:23:00 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *map, t_vars *vars)
{
	int fd;
	char *line;
	int columns;
	char *file;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	columns = 0;
	while (line != NULL)
	{
		file = (char *)malloc(strlen(line) - 1);
		file = line;
		printf("%s",file);
		printf("%s", line);
		free(line);
		printf("\n");
		// free(file);
		columns++;
		line = get_next_line(fd);
	}
	printf("\n");
	printf("%d\n",columns);
	close(fd);
}
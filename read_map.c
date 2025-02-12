/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:41:44 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/11 12:41:48 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *map, t_vars *vars)
{
	int fd;
	char *line;
	char	**readed_map;
	int columns;
	int	i;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		// readed_map[i];
		printf("%s", line);
		free(line);
		i++;
		
		line = get_next_line(fd);
	}
	close(fd);
}
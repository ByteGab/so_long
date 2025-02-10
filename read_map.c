/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:41:44 by gafreire          #+#    #+#             */
/*   Updated: 2025/02/10 15:51:46 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *map, t_vars *vars)
{
	int fd;
	char *line;
	int columns;
	int	i;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		while (line[i] != '\0')
		{
			if (line[i] == 1)
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->walls, (i * 16), 1);
			}
			i++;
		}
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
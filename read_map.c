/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:41:44 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 21:28:13 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(void)
{
	ft_printf("Error opening file");
	exit(EXIT_FAILURE);
}

void	read_map(char *argv, t_vars *vars)
{
	int		fd;
	char	*line;
	char	**file_map;

	vars->rows = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_map();
	line = get_next_line(fd);
	if (!line)
		error_map();
	vars->columns = (int)(ft_strlen(line) - 1);
	file_map = (char **)malloc(sizeof(char *) * 50);
	if (!file_map)
		error_map();
	while (line != NULL)
	{
		file_map[vars->rows] = ft_strdup(line);
		free(line);
		vars->rows++;
		line = get_next_line(fd);
	}
	file_map[vars->rows] = NULL;
	vars->map = file_map;
	close(fd);
}

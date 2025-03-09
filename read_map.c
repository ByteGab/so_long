/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:41:44 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 05:18:12 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(t_vars *vars)
{
	perror("Error opening file");
	clean_up(vars);
	exit(EXIT_FAILURE);
}

void	read_map(char *argv, t_vars *vars)
{
	int fd;
	char *line;
	int columns;
	int rows = 0;
	char **file_map;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_map(vars);
	line = get_next_line(fd);
	if (!line)
		error_map(vars);
	columns = ft_strlen(line) - 1;
	file_map = (char **)malloc(sizeof(char *) * 100);
	if (!file_map)
		error_map(vars);
	while (line != NULL)
	{
		file_map[rows] = ft_strdup(line);
		free(line);
		rows++;
		line = get_next_line(fd);
	}
	file_map[rows] = NULL;

	vars->map = file_map;
	vars->rows = rows;
	vars->columns = columns;
	close(fd);
}
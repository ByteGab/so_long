/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:41:44 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/07 00:13:58 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h> // quitar

// char **reco_map(t_data *data, char *argv)
// {
// 	t_map check_map;
// 	char **map = malloc(data->y * sizeof(char *));

// 	int i;
// 	i = 0;
// 	while (i < data->y)
// 	{
// 		map[i] = malloc (data->x[i] * sizeof (char));
// 		i++;
// 	}

// 	i  = 0;
// 	// comparar primera columna con los demas
// 	// while (map[i])
// 	// {
// 	// 	if (ft_strlen(map[i] != data->x[i])) // si solo hay tres columnas o no hay nada
// 	// 	{
// 	// 		check_map.check_rectangular == 1;
// 	// 		exit(0);
// 	// 	}
// 	// }
	
// }

void	read_map(char *argv, t_vars *vars)
{
	int fd;
	char *line;
	int columns;
	int rows = 0;
	char ** file_map;

	fd = open(argv, O_RDONLY);
	// if (fd < 0)
	// {
	// 	// perror("Error opening file");
    //     // exit(EXIT_FAILURE);
	// }
	line = get_next_line(fd);
	// if (!line)
    // {
    //     perror("Error reading file");
    //     exit(EXIT_FAILURE);
    // }
	columns = ft_strlen(line);
	file_map = (char **)malloc(sizeof(char *) * 100);
	// if (!file_map)
    // {
    //     perror("Error allocating memory");
    //     exit(EXIT_FAILURE);
    // }
	
	while (line != NULL)
	{
		file_map[rows] = strdup(line); // change strdup
		free(line);
		rows++;
		line = get_next_line(fd);
	}
	file_map[rows] = NULL;

	vars->map = file_map;
	vars->rows = rows;
	vars->columns = columns;
	printf("\n");
	// printf("%d\n",columns);
	close(fd);
}

void    print_map(t_vars *vars)
{
    for (int i = 0; i < vars->rows; i++)
    {
        printf("%s", vars->map[i]);
    }
}
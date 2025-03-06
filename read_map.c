/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:41:44 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/06 22:57:26 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **reco_map(t_data *data, char *argv)
{
	t_map check_map;
	char **map = malloc(data->y * sizeof(char *));

	int i;
	i = 0;
	while (i < data->y)
	{
		map[i] = malloc (data->x[i] * sizeof (char));
		i++;
	}

	i  = 0;
	// comparar primera columna con los demas
	// while (map[i])
	// {
	// 	if (ft_strlen(map[i] != data->x[i])) // si solo hay tres columnas o no hay nada
	// 	{
	// 		check_map.check_rectangular == 1;
	// 		exit(0);
	// 	}
	// }
	
}

void	read_map(char *argv, t_data *data)
{
	int fd;
	char *line;
	int columns;

	fd = open(argv, O_RDONLY);
	columns = 0;

	//file_map = (char **)malloc(strlen(line) - 1);
	while ((line = get_next_line(fd)) != NULL)
	{
		columns++;
		printf("%s", line);
		data->x[columns] = ft_strlen(line);
		free(line);
		// free(file);
	}
	data->y = columns;
	data->map = reco_map(data, argv);
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
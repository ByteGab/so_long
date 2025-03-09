/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:52:08 by gafreire          #+#    #+#             */
/*   Updated: 2025/03/09 21:52:55 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_newline(int fd, char *line_buffer, char *buffer)
{
	int	size;

	size = 1;
	while (!ft_strchr(line_buffer, '\n') && size > 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (free (buffer), free (line_buffer), line_buffer = NULL);
		buffer[size] = '\0';
		line_buffer = ft_strjoin(line_buffer, buffer);
		if (!line_buffer)
			return (free (buffer), NULL);
	}
	return (free (buffer), line_buffer);
}

char	*extract_remaining(char	*line_buffer)
{
	int		len;
	int		i;
	char	*rest;

	len = 0;
	i = 0;
	if (line_buffer == NULL)
		return (NULL);
	while (line_buffer[len] != '\n' && line_buffer[len])
		len++;
	if (line_buffer[len] == '\n')
		len++;
	rest = malloc((ft_strlen(line_buffer) - len + 1) * sizeof(char));
	if (!rest)
		return (free (line_buffer), NULL);
	while (line_buffer[len + i])
	{
		rest[i] = line_buffer[len + i];
		i++;
	}
	free (line_buffer);
	rest[i] = 0;
	return (rest);
}

char	*extract_new_line(char *line_buffer)
{
	int		len;
	int		i;
	char	*line;

	len = 0;
	i = 0;
	if (line_buffer == NULL)
		return (NULL);
	while (line_buffer[len] != '\n' && line_buffer[len])
		len++;
	if (line_buffer[len] == '\n')
		len++;
	if (len == 0)
		return (NULL);
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = line_buffer[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line_buffer;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(line_buffer);
		return (line_buffer = NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(line_buffer), line_buffer = NULL);
	line_buffer = read_newline(fd, line_buffer, buffer);
	if (line_buffer == NULL)
		return (NULL);
	line = extract_new_line(line_buffer);
	if (!line)
		return (free (line_buffer), line_buffer = NULL);
	line_buffer = extract_remaining(line_buffer);
	if (!line_buffer)
		return (free (line), NULL);
	if (*line_buffer == '\0')
		return (free(line_buffer), line_buffer = NULL, line);
	return (line);
}

// int main(void)
// {
// 	int	fd;
// 	char	*line;
// 	fd = open("primer_mapa.ber", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:52:11 by gafreire          #+#    #+#             */
/*   Updated: 2024/12/16 14:31:52 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	tab = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!tab)
		return (free(s1), NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = 0;
	free (s1);
	return (tab);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*mem;
	size_t	size;
	int		i;

	size = ft_strlen(s1) + 1;
	mem = (char *)malloc(size);
	i = 0;
	if (!mem)
		return (NULL);
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowerhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:37:31 by gafreire          #+#    #+#             */
/*   Updated: 2024/11/10 16:55:12 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowerhex(unsigned int n)
{
	int		size_format;
	char	*basehex;

	size_format = 0;
	basehex = "0123456789abcdef";
	if (n >= 16)
	{
		size_format += ft_lowerhex(n / 16);
		size_format += ft_lowerhex(n % 16);
	}
	else
		size_format += ft_putcharint(basehex[n % 16]);
	return (size_format);
}

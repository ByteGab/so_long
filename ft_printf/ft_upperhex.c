/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upperhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:41:24 by gafreire          #+#    #+#             */
/*   Updated: 2024/11/10 17:29:11 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upperhex(unsigned int n)
{
	int		size_format;
	char	*basehex;

	size_format = 0;
	basehex = "0123456789ABCDEF";
	if (n >= 16)
	{
		size_format += ft_upperhex(n / 16);
		size_format += ft_upperhex(n % 16);
	}
	else
		size_format += ft_putcharint(basehex[n % 16]);
	return (size_format);
}

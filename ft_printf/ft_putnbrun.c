/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:33:34 by gafreire          #+#    #+#             */
/*   Updated: 2024/11/10 16:56:12 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrun(unsigned int n)
{
	unsigned int	size_format;

	size_format = 0;
	if (n > 9)
	{
		size_format += ft_putnbrint(n / 10);
		size_format += ft_putnbrint(n % 10);
	}
	else
		size_format += ft_putcharint(n + '0');
	return (size_format);
}

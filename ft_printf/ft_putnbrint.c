/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:35:25 by gafreire          #+#    #+#             */
/*   Updated: 2024/11/10 15:12:05 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrint(int n)
{
	int	size_format;

	size_format = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		size_format += ft_putcharint('-');
		n = -n;
	}
	if (n > 9)
	{
		size_format += ft_putnbrint(n / 10);
		size_format += ft_putnbrint(n % 10);
	}
	else
		size_format += ft_putcharint(n + '0');
	return (size_format);
}

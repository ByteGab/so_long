/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:41:29 by gafreire          #+#    #+#             */
/*   Updated: 2024/11/10 18:23:58 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	strlenhex(unsigned long long n)
{
	int	size_format;

	size_format = 0;
	if (n <= 0)
		size_format++;
	while (n)
	{
		n /= 16;
		size_format++;
	}
	return (size_format);
}

static void	puthex(unsigned long long n)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (n >= 16)
	{
		puthex(n / 16);
		puthex(n % 16);
	}
	else
		ft_putcharint((int)base_hex[n % 16]);
}

int	ft_voidhex(void *n)
{
	int					size_format;
	unsigned long long	nl;

	size_format = 0;
	if (n == NULL)
	{
		size_format += ft_putstrint("(nil)");
		return (size_format);
	}
	nl = (unsigned long long)n;
	size_format += ft_putstrint("0x");
	puthex(nl);
	size_format += strlenhex(nl);
	return (size_format);
}

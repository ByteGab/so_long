/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:08:26 by gafreire          #+#    #+#             */
/*   Updated: 2024/11/10 17:41:16 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	formats(va_list arguments, char format)
{
	int	size_format;

	size_format = 0;
	if (format == 'c')
		size_format = ft_putcharint(va_arg(arguments, int));
	else if (format == 's')
		size_format = ft_putstrint(va_arg(arguments, char *));
	else if (format == 'p')
		size_format = ft_voidhex(va_arg(arguments, void *));
	else if (format == 'd' || format == 'i')
		size_format = ft_putnbrint(va_arg(arguments, int));
	else if (format == 'u')
		size_format = ft_putnbrun(va_arg(arguments, int));
	else if (format == 'x')
		size_format = ft_lowerhex(va_arg(arguments, unsigned int));
	else if (format == 'X')
		size_format = ft_upperhex(va_arg(arguments, unsigned int));
	else if (format == '%')
		size_format = ft_putcharint('%');
	return (size_format);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		value;
	va_list	arguments;

	i = 0;
	value = 0;
	va_start(arguments, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '\0')
			{
				value += formats(arguments, format[i + 1]);
				i++;
			}
		}
		else
			value += ft_putcharint(format[i]);
		i++;
	}
	va_end(arguments);
	return (value);
}
/*
#include <stdio.h>

int	main(void)
{
	int	print;
	int	*paco;
	int	*paco1;

	paco = 0;
	print = ft_printf(" %x", 426);
	printf("%p", NULL);
	printf("%p", paco);
	//ft_printf("\n");
	//ft_printf("%i", print);
	//ft_printf("\n");
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafreire <gafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:14:17 by gafreire          #+#    #+#             */
/*   Updated: 2024/11/09 19:17:28 by gafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_printf(char const *format, ...);
int	ft_putcharint(int c);
int	ft_putstrint(char *s);
int	ft_voidhex(void *n);
int	ft_putnbrint(int n);
int	ft_putnbrun(unsigned int n);
int	ft_upperhex(unsigned int n);
int	ft_lowerhex(unsigned int n);

#endif
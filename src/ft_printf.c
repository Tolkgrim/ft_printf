/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:54:19 by jdutschk          #+#    #+#             */
/*   Updated: 2022/03/22 19:40:26 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_verif(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar_printf(va_arg(arg, char *), 1));
	if (c == 's')
		return (ft_putstr_prni
	if (c == 'p')
		return (ft_p_ptr(va_arg(arg, unsigned long long)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_printf(va_arg(arg, int)));
	if (c == 'u')
		return (ft_putnbr1_printf(va_arg(arg, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg(arg, unsigned int), c));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	result;
	va_list	arg;

	i = 0;
	result = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			result = result + ft_verif(format[i + 1], arg);
			i++;
		}
		else
		{
			ft_putchar(format[i], 1);
			result++;
		}	
	i++;
	}
	va_end(arg);
	return (result);
}

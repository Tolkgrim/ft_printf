/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 23:34:45 by jdutschk          #+#    #+#             */
/*   Updated: 2022/03/22 19:39:40 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_ptrlen(unsigned long long ptr)
{
	int	i;

	i = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		i++;
	}
	return (i);
}

void	ft_putptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_putchar(ptr + '0', 1);
		else
			ft_putchar((ptr - 10) + 'a', 1);
	}
}

int	ft_p_ptr(unsigned long long ptr)
{
	int	p_len;

	p_len = 0;
	p_len += write(1, "0x", 2);
	if (!ptr)
		p_len += write(1, "0", 1);
	else
	{
		ft_putptr(ptr);
		p_len += ft_ptrlen(ptr);
	}
	return (p_len);
}

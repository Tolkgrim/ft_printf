/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:25:10 by jdutschk          #+#    #+#             */
/*   Updated: 2022/03/22 19:40:29 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putchar_printf(char *c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_printf(char *s)
{
	if (!s)
	{
		ft_printf("(null)");
		return (6);
	}
	write (1, s, ft_printf_strlen(s));
	return (ft_printf_strlen(s));
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

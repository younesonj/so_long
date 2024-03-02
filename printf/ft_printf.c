/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:07:43 by younajja          #+#    #+#             */
/*   Updated: 2023/11/27 22:31:17 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	valverdefct(char str, int i, va_list args)
{
	if (str == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (str == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (str == 'd' || str == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		i += ft_putunsigned(va_arg(args, unsigned int));
	else if (str == 'x')
		i += ft_hex(va_arg(args, unsigned int));
	else if (str == 'X')
		i += ft_upphex(va_arg(args, unsigned int));
	else if (str == 'p')
	{
		i += ft_putadress(va_arg(args, unsigned long));
	}
	else if (str == '%')
		i += ft_putchar(str);
	else
		i += ft_putchar(str);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	if (str == NULL)
		return (-1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i = valverdefct(*str, i, args);
		}
		else
			i += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (i);
}

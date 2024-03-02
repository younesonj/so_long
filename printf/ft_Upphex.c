/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Upphex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 03:09:34 by younajja          #+#    #+#             */
/*   Updated: 2023/11/27 03:54:10 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upphex(unsigned int n)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (n < 16)
		i += write(1, hex + n, 1);
	else if (n >= 16)
	{
		i += ft_upphex(n / 16);
		i += ft_upphex(n % 16);
	}
	return (i);
}

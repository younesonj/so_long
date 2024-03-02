/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:25:39 by younajja          #+#    #+#             */
/*   Updated: 2024/03/02 18:18:22 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_msg(char *str)
{
	printf("Error!\n%s", str);
	exit(1);
}

int	calcul_len(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	ft_all_is_one(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			ft_exit_msg("map is not closed!");
		i++;
	}
	return (0);
}

int	ft_check_f_l_one(char *str)
{
	int	last;

	last = ft_strlen(str) - 1;
	if (str[0] != '1' || str[last] != '1')
		ft_exit_msg("the is not closed!");
	return (0);
}

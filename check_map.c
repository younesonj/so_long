/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:52 by younajja          #+#    #+#             */
/*   Updated: 2024/03/02 18:43:34 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_close(char **strs)
{
	int	len;
	int	i;

	i = 0;
	len = calcul_len(strs);
	while (i < len)
	{
		if ((i == len - 1) || (i == 0))
			ft_all_is_one(strs[i]);
		else
			ft_check_f_l_one(strs[i]);
		i++;
	}
	return (0);
}

int	ft_check_shape(char **strs)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(strs[i]);
	while (strs[i])
	{
		if (len != ft_strlen(strs[i]))
			ft_exit_msg("shape of map not valid!");
		i++;
	}
	return (0);
}

int	ft_count_char(char **strs, char C)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == C)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_check_char_valid(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] != '1' && strs[i][j] != '0' && strs[i][j] != 'C'
				&& strs[i][j] != 'P' && strs[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_characters(char **strs)
{
	if (ft_count_char(strs, 'P') != 1 || ft_count_char(strs, 'E') != 1
		|| !ft_check_char_valid(strs) || ft_count_char(strs, 'C') < 1)
		ft_exit_msg("Problem in characters in map!");
	return (0);
}

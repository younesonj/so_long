/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:17 by younajja          #+#    #+#             */
/*   Updated: 2024/03/05 17:36:21 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_if_coin(char **strs, int i, int j, char sign)
{
	if (strs[i][j] == 'P' && sign == 'R' && strs[i][j + 1] == 'C')
	{
		ft_swap(&strs[i][j], &strs[i][j + 1]);
		strs[i][j] = '0';
		return (0);
	}
	else if (strs[i][j] == 'P' && sign == 'L' && strs[i][j - 1] == 'C')
	{
		ft_swap(&strs[i][j], &strs[i][j - 1]);
		strs[i][j] = '0';
		return (0);
	}
	else if (strs[i][j] == 'P' && sign == 'U' && strs[i - 1][j] == 'C')
	{
		ft_swap(&strs[i][j], &strs[i - 1][j]);
		strs[i][j] = '0';
		return (0);
	}
	else if (strs[i][j] == 'P' && sign == 'D' && strs[i + 1][j] == 'C')
	{
		ft_swap(&strs[i][j], &strs[i + 1][j]);
		strs[i][j] = '0';
		return (0);
	}
	return (1);
}

int	ft_move_if_empty(char **strs, int i, int j, char sign)
{
	if (strs[i][j] == 'P' && sign == 'R' && strs[i][j + 1] == '0')
	{
		ft_swap(&strs[i][j], &strs[i][j + 1]);
		return (0);
	}
	else if (strs[i][j] == 'P' && sign == 'L' && strs[i][j - 1] == '0')
	{
		ft_swap(&strs[i][j], &strs[i][j - 1]);
		return (0);
	}
	else if (strs[i][j] == 'P' && sign == 'U' && strs[i - 1][j] == '0')
	{
		ft_swap(&strs[i][j], &strs[i - 1][j]);
		return (0);
	}
	else if (strs[i][j] == 'P' && sign == 'D' && strs[i + 1][j] == '0')
	{
		ft_swap(&strs[i][j], &strs[i + 1][j]);
		return (0);
	}
	return (1);
}

int	ft_move_if_exit(char **strs, int i, int j, char sign)
{
	if (strs[i][j] == 'P' && sign == 'R' && strs[i][j + 1] == 'E'
		&& !ft_check_if_c_expired(strs))
		return (0);
	else if (strs[i][j] == 'P' && sign == 'L' && strs[i][j - 1] == 'E'
		&& !ft_check_if_c_expired(strs))
		return (0);
	else if (strs[i][j] == 'P' && sign == 'U' && strs[i - 1][j] == 'E'
		&& !ft_check_if_c_expired(strs))
		return (0);
	else if (strs[i][j] == 'P' && sign == 'D' && strs[i + 1][j] == 'E'
		&& !ft_check_if_c_expired(strs))
		return (0);
	return (1);
}

int	ft_check_move(t_list *game, char sign, int i, int j)
{
	char	**strs;

	strs = game->map;
	if ((ft_move_if_empty(strs, i, j, sign) == 0) || (ft_move_if_coin(strs, i,
				j, sign) == 0) || (ft_move_if_exit(strs, i, j, sign) == 0))
	{
		ft_printf("move : %d\n", game->num_move++);
		if (ft_move_if_exit(strs, i, j, sign) == 0)
		{
			ft_free(game->map);
			ft_free_mlx(game);
			ft_printf("FINIIITOO\n");
			exit(0);
		}
		return (0);
	}
	return (1);
}

void	ft_move_p(t_list *game, char sign)
{
	char	**strs;
	int		i;
	int		j;

	strs = game->map;
	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (ft_check_move(game, sign, i, j) == 0)
				return ;
			j++;
		}
		i++;
	}
}

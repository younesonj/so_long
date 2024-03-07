/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:00:31 by younajja          #+#    #+#             */
/*   Updated: 2024/03/06 11:48:10 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(int x, int y, char **map)
{
	if (x < 0 || x >= calcul_len(map) || y < 0 || y >= (int)ft_strlen(map[0])
		|| map[x][y] == '1' || map[x][y] == 'E' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	ft_flood_fill(x + 1, y, map);
	ft_flood_fill(x - 1, y, map);
	ft_flood_fill(x, y - 1, map);
	ft_flood_fill(x, y + 1, map);
}

int	ft_judge(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || (map[i][j] == 'E' && map[i - 1][j] != 'V'
					&& map[i + 1][j] != 'V' && map[i][j - 1] != 'V'
					&& map[i][j] != 'V'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_path(char **strs)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	y = 0;
	map = ft_cpy_strs(strs);
	ft_position_of_player(&x, &y, map);
	ft_flood_fill(x, y, map);
	if (ft_judge(map) == 1)
	{
		ft_free(strs);
		ft_free(map);
		ft_exit_msg("flood fill akhaay");
	}
	ft_free(map);
}

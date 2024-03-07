/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:13 by younajja          #+#    #+#             */
/*   Updated: 2024/03/07 02:08:48 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(char *map_name)
{
	int		fd;
	char	*str;
	char	*res;
	char	**last_vrs;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_exit_msg("There is no file !");
	str = get_next_line(fd);
	if (!str)
	{
		ft_exit_msg("NO MAP!");
	}
	res = ft_strdup("");
	while (str)
	{
		res = ft_strjoin_gnl(res, str);
		free(str);
		str = get_next_line(fd);
	}
	ft_check_space(res);
	last_vrs = ft_split(res, '\n');
	free(res);
	return (last_vrs);
}

char	**last_form(char *name_arg, t_list *game)
{
	char	**last;

	last = ft_read_map(name_arg);
	ft_check_shape(last);
	ft_check_close(last);
	ft_check_characters(last);
	ft_check_path(last);
	game->map = ft_cpy_strs(last);
	ft_free(last);
	return (game->map);
}

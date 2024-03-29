/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:46 by younajja          #+#    #+#             */
/*   Updated: 2024/03/07 01:15:50 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image(char c, t_list *game, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx_cnx, game->window, game->wall, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx_cnx, game->window, game->player, x,
			y);
	else if (c == 'L')
		mlx_put_image_to_window(game->mlx_cnx, game->window, game->player_left,
			x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx_cnx, game->window, game->empty, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx_cnx, game->window, game->coin, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx_cnx, game->window, game->exit, x, y);
}

void	ft_draw_map_row(char *row, t_list *game, int y)
{
	int	x;
	int	j;

	x = 0;
	j = 0;
	while (row[j])
	{
		ft_put_image(row[j], game, x, y);
		x = x + 64;
		j++;
	}
}

void	ft_draw_map(t_list *game)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (game->map[i])
	{
		ft_draw_map_row(game->map[i], game, y);
		i++;
		y = y + 64;
	}
}

void	ft_setting_images(t_list *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx_cnx, "xpm/wall.xpm", &game->he,
			&game->wd);
	ft_wall_fail(game);
	game->player = mlx_xpm_file_to_image(game->mlx_cnx, "xpm/player.xpm",
			&game->he, &game->wd);
	ft_player_fail(game);
	game->player_left = mlx_xpm_file_to_image(game->mlx_cnx,
			"xpm/player_left.xpm", &game->he, &game->wd);
	ft_player_left_fail(game);
	game->empty = mlx_xpm_file_to_image(game->mlx_cnx, "xpm/empty.xpm",
			&game->he, &game->wd);
	ft_empty_fail(game);
	game->coin = mlx_xpm_file_to_image(game->mlx_cnx, "xpm/coin.xpm", &game->he,
			&game->wd);
	ft_coin_fail(game);
	game->exit = mlx_xpm_file_to_image(game->mlx_cnx, "xpm/exit.xpm", &game->he,
			&game->wd);
	ft_exit_fail(game);
}

void	ft_setting_map(t_list *game)
{
	game->mlx_cnx = mlx_init();
	game->height = calcul_len(game->map) * 64;
	game->width = ft_strlen(game->map[0]) * 64;
	ft_setting_images(game);
	game->window = mlx_new_window(game->mlx_cnx, game->width, game->height,
			"Map display");
}

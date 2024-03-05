/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:40 by younajja          #+#    #+#             */
/*   Updated: 2024/03/05 17:38:35 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_search_p(char **strs, char find, char replace)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == find)
			{
				strs[i][j] = replace;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_key_hook(int keycode, t_list *game)
{
	if (keycode == 65307)
	{
		ft_free(game->map);
		ft_printf("You've pressed \"Esc\"");
		ft_free_mlx(game);
		exit(0);
	}
	else if (keycode == 65361)
	{
		ft_move_p(game, 'L');
		ft_search_p(game->map, 'P', 'L');
	}
	else if (keycode == 65363)
		ft_move_p(game, 'R');
	else if (keycode == 65362)
		ft_move_p(game, 'U');
	else if (keycode == 65364)
		ft_move_p(game, 'D');
	mlx_clear_window(game->mlx_cnx, game->window);
	ft_draw_map(game);
	ft_search_p(game->map, 'L', 'P');;
	return (0);
}

int	ft_close_window(t_list *game)
{
	ft_printf("Window closed!");
	ft_free(game->map);
	ft_free_mlx(game);
	exit(0);
	return (0);
}

int	ft_check_name_map(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	if (count != 1)
		ft_exit_msg("Map name not valid!");
	i = 0;
	while (str[i] != '.')
		i++;
	if (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r')
		return (0);
	else
		return (1);
}

int	main(int ac, char **av)
{
	t_list	game;

	if (ac != 2)
		ft_exit_msg("PLease enter the map !");
	if (ft_check_name_map(av[1]))
		ft_exit_msg("Map name not valid!");
	game.num_move = 1;
	last_form(av[1], &game);
	ft_setting_map(&game);
	ft_draw_map(&game);
	mlx_key_hook(game.window, ft_key_hook, &game);
	mlx_hook(game.window, 17, 0, ft_close_window, &game);
	mlx_loop(game.mlx_cnx);
}

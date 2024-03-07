/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zadto_norme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 02:29:56 by younajja          #+#    #+#             */
/*   Updated: 2024/03/07 02:31:27 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_and_exit(char **strs)
{
	ft_free(strs);
	ft_exit_msg("map is not closed!");
}

void	ft_exit_fail(t_list *game)
{
	if (!game->exit)
	{
		ft_free(game->map);
		mlx_destroy_image(game->mlx_cnx, game->wall);
		mlx_destroy_image(game->mlx_cnx, game->player);
		mlx_destroy_image(game->mlx_cnx, game->player_left);
		mlx_destroy_image(game->mlx_cnx, game->empty);
		mlx_destroy_image(game->mlx_cnx, game->coin);
		mlx_destroy_display(game->mlx_cnx);
		free(game->mlx_cnx);
		ft_exit_msg("Path to \"exit\" image not found!");
	}
}

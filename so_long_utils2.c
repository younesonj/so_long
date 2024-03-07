/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:05:28 by younajja          #+#    #+#             */
/*   Updated: 2024/03/07 01:11:40 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_free(char **strs)
{
    int len;

    len = calcul_len(strs);
    while (len >= 0)
    {
        free(strs[len]);
        len--;
    }
    free(strs);
}

void    ft_free_mlx(t_list *game)
{
    mlx_destroy_window(game->mlx_cnx, game->window);
	mlx_destroy_display(game->mlx_cnx);
	free(game->mlx_cnx);
}

char    **ft_cpy_strs(char **strs)
{
    char    **map;
    int     len;
    int     i;

    i = 0;
    len = calcul_len(strs);
    map = (char **)malloc ((len + 1) * sizeof(char *));
    while (i < len)
    {
        map[i] = ft_strdup(strs[i]);
        i++;
    }
    map[i] = 0;
    return (map);
}

void    ft_free_image(t_list *game)
{
    mlx_destroy_image(game->mlx_cnx, game->wall);
    mlx_destroy_image(game->mlx_cnx, game->player);
    mlx_destroy_image(game->mlx_cnx, game->player_left);
    mlx_destroy_image(game->mlx_cnx, game->empty);
    mlx_destroy_image(game->mlx_cnx, game->coin);
    mlx_destroy_image(game->mlx_cnx, game->exit);
}

// void    ft_free_mlx_and_images(t_list *game)
// {
//     ft_free_image(game);
//     ft_free_mlx(game);
// }
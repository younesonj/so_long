/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 22:43:10 by younajja          #+#    #+#             */
/*   Updated: 2024/03/07 01:13:29 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_wall_fail(t_list *game)
{
    if (!game->wall)
    {
        ft_free(game->map);
	    mlx_destroy_display(game->mlx_cnx);
        free(game->mlx_cnx);
        ft_exit_msg("Path to \"wall\" image not found!");    
    }
}

void    ft_player_fail(t_list *game)
{
    if (!game->player)
    {
        ft_free(game->map);
        mlx_destroy_image(game->mlx_cnx, game->wall);
	    mlx_destroy_display(game->mlx_cnx);
        free(game->mlx_cnx);
        ft_exit_msg("Path to \"player\" image not found!");  
    }
}

void    ft_player_left_fail(t_list *game)
{
    if (!game->player_left)
    {
        ft_free(game->map);
        mlx_destroy_image(game->mlx_cnx, game->wall);
        mlx_destroy_image(game->mlx_cnx, game->player);
	    mlx_destroy_display(game->mlx_cnx);
        free(game->mlx_cnx);
        ft_exit_msg("Path to \"player_left\" image not found!");   
    }
}

void    ft_empty_fail(t_list *game)
{
    if (!game->empty)
    {
        ft_free(game->map);
        mlx_destroy_image(game->mlx_cnx, game->wall);
        mlx_destroy_image(game->mlx_cnx, game->player);
        mlx_destroy_image(game->mlx_cnx, game->player_left);
	    mlx_destroy_display(game->mlx_cnx);
        free(game->mlx_cnx);
        ft_exit_msg("Path to \"empty\" image not found!");
    }

}

void    ft_coin_fail(t_list *game)
{
    if (!game->coin)
    {
        ft_free(game->map);
        mlx_destroy_image(game->mlx_cnx, game->wall);
        mlx_destroy_image(game->mlx_cnx, game->player);
        mlx_destroy_image(game->mlx_cnx, game->player_left);
        mlx_destroy_image(game->mlx_cnx, game->empty);
	    mlx_destroy_display(game->mlx_cnx);
        free(game->mlx_cnx);
        ft_exit_msg("Path to \"coin\" image not found!"); 
    }

}

void    ft_exit_fail(t_list *game)
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


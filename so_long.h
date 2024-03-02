/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:03 by younajja          #+#    #+#             */
/*   Updated: 2024/03/02 18:24:48 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"
# include <mlx.h>
# include <stdio.h>

typedef struct t_list
{
	char	**map;
	void	*mlx_cnx;
	void	*window;
	int		height;
	int		width;
	void	*wall;
	void	*player;
	void	*player_left;
	void	*empty;
	void	*coin;
	void	*exit;
	int		he;
	int		wd;
	int		num_move;
}			t_list;

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
void		ft_exit_msg(char *str);
int			calcul_len(char **strs);
int			ft_check_close(char **strs);
int			ft_check_shape(char **strs);
int			ft_check_characters(char **strs);
char		**last_form(char *name_arg);
void		ft_draw_map(char **map, t_list *game);
void		ft_setting_map(char *str, t_list *game);
void		ft_move_p(t_list *game, char sign);
int			ft_all_is_one(char *str);
int			ft_check_f_l_one(char *str);
void		ft_swap(char *a, char *b);
int			ft_check_if_c_expired(char **strs);

#endif
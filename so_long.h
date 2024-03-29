/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:26:03 by younajja          #+#    #+#             */
/*   Updated: 2024/03/07 02:33:45 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"
# include <mlx.h>

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
char		**last_form(char *name_arg, t_list *game);
void		ft_draw_map(t_list *game);
void		ft_setting_map(t_list *game);
void		ft_move_p(t_list *game, char sign);
int			ft_all_is_one(char *str);
int			ft_check_f_l_one(char *str);
void		ft_swap(char *a, char *b);
int			ft_check_if_c_expired(char **strs);
void		ft_position_of_player(int *x, int *y, char **map);
void		ft_check_path(char **strs);
void		ft_free(char **strs);
char		**ft_cpy_strs(char **strs);
void		ft_free_mlx(t_list *game);
void		ft_free_image(t_list *game);
void		ft_free_mlx_and_images(t_list *game);
void		ft_wall_fail(t_list *game);
void		ft_player_fail(t_list *game);
void		ft_player_left_fail(t_list *game);
void		ft_empty_fail(t_list *game);
void		ft_coin_fail(t_list *game);
void		ft_exit_fail(t_list *game);
void		ft_check_space(char *str);
void		ft_free_and_exit(char **strs);

#endif
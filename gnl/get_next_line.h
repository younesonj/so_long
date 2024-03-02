/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:20:17 by younajja          #+#    #+#             */
/*   Updated: 2023/12/12 21:20:44 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *line, char *buff);
char	*ft_strchr_gnl(char *s, int c);
size_t	ft_strlen1(char *s);
char	*ft_extract(int fd, char *line);
char	*ft_cut_first(char *line);
char	*ft_cut_last(char *line);

#endif

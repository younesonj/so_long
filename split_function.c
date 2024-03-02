/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younajja <younajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:50:09 by younajja          #+#    #+#             */
/*   Updated: 2024/03/02 18:26:22 by younajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_equal(char const s, char c)
{
	if ((char)s == c)
		return (1);
	else
		return (0);
}

static int	count(char const *s, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (check_equal((s[i]), c) == 1)
			i++;
		else if (check_equal(s[i], c) == 0)
		{
			while (s[i] != c && s[i])
				i++;
			j++;
		}
	}
	return (j);
}

static char	**free_al(char **ptr, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(ptr[j]);
		ptr[j] = NULL;
		j++;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

static char	**mini(char const *s, char **str, char c, size_t length)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	end = 0;
	while (i < length)
	{
		while (s[start] == c && s[start])
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		str[i] = ft_substr(s, start, end - start);
		if (!str[i])
			return (free_al(str, i));
		i++;
		start = end;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	length;

	if (!s)
		return (NULL);
	length = count(s, c);
	str = malloc((length + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	return (mini(s, str, c, length));
}

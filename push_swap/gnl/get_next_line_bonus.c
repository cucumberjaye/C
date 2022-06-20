/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:42:29 by cjaye             #+#    #+#             */
/*   Updated: 2021/11/21 13:42:38 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*one_line(char **str, int c, int *i)
{
	char	*res;
	char	*new;
	int		l;

	l = 0;
	if (c == 0)
		l = 1;
	while (*i < (int)ft_strlen(*str) + l)
	{
		if ((*str)[*i] == '\n' || (*str)[*i] == '\0')
		{
			res = ft_strdup(*str, *i + 1);
			new = *str;
			*str = ft_strdup(*str + *i + 1, ft_strlen(*str + *i + 1));
			free(new);
			*str = ft_realloc(*str, ft_strlen(*str), c);
			return (res);
		}
		++(*i);
	}
	return (NULL);
}

static int	half(char **res, char **str, int c)
{
	if (!(*res))
	{
		*str = ft_realloc(*str, ft_strlen(*str), c);
		return (0);
	}
	else
	{
		if ((*res)[0] == '\0')
		{
			free(*res);
			*res = NULL;
			return (1);
		}
		return (1);
	}
}

static int	cread(int c, char **str, int i)
{
	if (c < 0)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	(*str)[i + c] = '\0';
	return (0);
}

static char	*free_str(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	int			c;
	static char	*str = NULL;
	char		*res;
	int			i;
	int			k;

	k = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_calloc(BUFFER_SIZE + 1, 1);
	while (1)
	{
		i = ft_strlen(str);
		c = read(fd, str + i, BUFFER_SIZE);
		if (cread(c, &str, i) == 1)
			return (NULL);
		res = one_line(&str, c, &k);
		if (half(&res, &str, c) == 1)
			break ;
	}
	if (res != NULL)
		return (res);
	str = free_str(str);
	return (res);
}

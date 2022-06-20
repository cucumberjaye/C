/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:34:04 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/27 16:34:05 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*one_line(char **str, int c)
{
	char		*res;
	static int	i = 0;
	char		*new;
	int			l;

	l = 0;
	if (c == 0)
		l = 1;
	while (i < (int)ft_strlen(*str) + l)
	{
		if ((*str)[i] == '\n' || (*str)[i] == '\0')
		{
			res = ft_strdup(*str, i);
			new = *str;
			*str = ft_strdup(*str + i + 1, ft_strlen(*str + i + 1));
			free(new);
			*str = ft_realloc(*str, ft_strlen(*str), c);
			i = 0;
			return (res);
		}
		++i;
	}
	return (NULL);
}

static int	half(char **res, char **str, int *i, int c)
{
	if (!(*res))
	{
		*str = ft_realloc(*str, ft_strlen(*str), c);
		*i += c;
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
		*i = ft_strlen(*str);
		return (1);
	}
}

static int	cread(int c, char **str)
{
	if (c < 0)
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			c;
	static char	*str = NULL;
	char		*res;
	static int	i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_calloc(BUFFER_SIZE + 1, 1);
	while (1)
	{
		c = read(fd, str + i, BUFFER_SIZE);
		if (cread(c, &str) == 1)
			return (NULL);
		str[i + c] = '\0';
		res = one_line(&str, c);
		if (half(&res, &str, &i, c) == 1)
			break ;
	}
	if (res != NULL)
		return (res);
	free(str);
	str = NULL;
	return (res);
}

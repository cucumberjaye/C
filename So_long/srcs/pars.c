/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/28 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	er(char *str, int fd)
{
	free(str);
	write(2, "Error\nThe map must be rectangular\n", 34);
	close(fd);
	return (1);
}

static int	map_size(char *map, t_par *par)
{
	int		fd;
	char	*str;
	int		len;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (write(2, "Invalid fd\n", 11));
	par->width = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		len = ft_strlen(str);
		if (par->width == 0)
			par->length = len;
		if (len != par->length)
			return (er(str, fd));
		++par->width;
		free(str);
	}
	close(fd);
	return (0);
}

char	**pars(char *map, t_par *par)
{
	int		fd;
	char	**content;
	int		i;

	if (map_size(map, par) != 0)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Invalid fd\n", 11);
		return (NULL);
	}
	i = 0;
	content = (char **)malloc(sizeof(char *) * par->width);
	while (i < par->width)
	{
		content[i] = get_next_line(fd);
		++i;
	}
	get_next_line(fd);
	close(fd);
	return (content);
}

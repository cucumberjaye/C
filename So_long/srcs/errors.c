/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/28 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walls(char **map, t_par *par)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < par->width)
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || j == 0 || i == par->width - 1 || j == par->length - 1)
				if (map[i][j] != '1')
					return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	cep(char **map, t_par *par)
{
	int	i;
	int	j;

	i = 0;
	while (i < par->width)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				++par->c;
			if (map[i][j] == 'E')
				++par->exits;
			if (map[i][j] == 'P')
				++par->player;
			++j;
		}
		++i;
	}
	if (par->c == 0 || par->exits == 0 || par->player != 1)
		return (1);
	return (0);
}

int	contain(char **map, t_par *par)
{
	int	i;
	int	j;

	i = 0;
	while (i < par->width)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P'
				&& map[i][j] != '0' && map[i][j] != '1')
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	errors(char **map, t_par *par)
{
	par->c = 0;
	par->exits = 0;
	par->player = 0;
	par->steps = 0;
	if (walls(map, par) == 1)
		return (write(2, "Error\nThe map must be closed by walls\n", 38));
	if (cep(map, par) == 1)
		return (write(2, "Error\nNeed at least 1 E, 1 C, and 1 P.\n", 55));
	if (contain(map, par) == 1)
		return (write(2, "Error\nInvalid parameter in the map\n", 35));
	return (0);
}

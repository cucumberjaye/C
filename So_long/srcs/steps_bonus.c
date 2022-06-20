/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/28 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	textures_bonus(t_par *par)
{
	int		i;
	int		j;

	image_bonus(par);
	i = 0;
	while (i < par->width)
	{
		j = 0;
		while (j < par->length)
		{
			img_place_bonus(par, par->map[i][j], i, j);
			++j;
		}
		++i;
	}
	player_place(par);
}

void	play_bonus(t_par *par)
{
	mlx_key_hook(par->win, keybord_bonus, par);
	mlx_hook(par->win, 17, 1L << 17, mouse, par);
	mlx_loop_hook(par->mlx, sprite, par);
	mlx_loop(par->mlx);
}

int	contain_bonus(char **map, t_par *par)
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
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'V')
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	errors_bonus(char **map, t_par *par)
{
	par->c = 0;
	par->exits = 0;
	par->player = 0;
	par->steps = 0;
	if (walls(map, par) == 1)
		return (write(2, "Error\nThe map must be closed by walls\n", 38));
	if (cep(map, par) == 1)
		return (write(2, "Error\nNeed at least 1 E, 1 C, and 1 P.\n", 84));
	if (contain_bonus(map, par) == 1)
		return (write(2, "Error\nInvalid parameter in the map\n", 35));
	return (0);
}

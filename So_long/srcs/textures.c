/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/28 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_place(t_par *par, char map, int i, int j)
{
	if (map == '0')
		mlx_put_image_to_window(par->mlx, par->win, par->i[0], j * 50, i * 50);
	if (map == '1')
		mlx_put_image_to_window(par->mlx, par->win, par->i[1], j * 50, i * 50);
	if (map == 'P')
		mlx_put_image_to_window(par->mlx, par->win, par->i[2], j * 50, i * 50);
	if (map == 'C')
		mlx_put_image_to_window(par->mlx, par->win, par->i[3], j * 50, i * 50);
	if (map == 'E')
		mlx_put_image_to_window(par->mlx, par->win, par->i[4], j * 50, i * 50);
}

void	image(t_par *par)
{
	int	s;

	s = 50;
	par->i[0] = mlx_xpm_file_to_image(par->mlx, "images/road.xpm", &s, &s);
	par->i[1] = mlx_xpm_file_to_image(par->mlx, "images/house.xpm", &s, &s);
	par->i[2] = mlx_xpm_file_to_image(par->mlx, "images/raf.xpm", &s, &s);
	par->i[3] = mlx_xpm_file_to_image(par->mlx, "images/pizza.xpm", &s, &s);
	par->i[4] = mlx_xpm_file_to_image(par->mlx, "images/luke.xpm", &s, &s);
	par->i[5] = mlx_xpm_file_to_image(par->mlx, "images/rl.xpm", &s, &s);
	par->i[6] = mlx_xpm_file_to_image(par->mlx, "images/shell.xpm", &s, &s);
}

void	player_place(t_par *par)
{
	int	i;
	int	j;

	i = 0;
	while (i < par->width)
	{
		j = 0;
		while (j < par->length)
		{
			if (par->map[i][j] == 'P')
			{
				par->pp[0] = i;
				par->pp[1] = j;
			}
			++j;
		}
		++i;
	}
}

void	textures(t_par *par)
{
	int		i;
	int		j;

	image(par);
	i = 0;
	while (i < par->width)
	{
		j = 0;
		while (j < par->length)
		{
			img_place(par, par->map[i][j], i, j);
			++j;
		}
		++i;
	}
	player_place(par);
}

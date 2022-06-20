/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/28 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_map(char **map, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(map[i]);
		++i;
	}
	free(map);
	return (1);
}

int	free_par(t_par *par)
{
	mlx_destroy_image(par->mlx, par->i[0]);
	mlx_destroy_image(par->mlx, par->i[1]);
	mlx_destroy_image(par->mlx, par->i[2]);
	mlx_destroy_image(par->mlx, par->i[3]);
	mlx_destroy_image(par->mlx, par->i[4]);
	mlx_destroy_image(par->mlx, par->i[5]);
	mlx_destroy_image(par->mlx, par->i[6]);
	mlx_destroy_window(par->mlx, par->win);
	mlx_destroy_display(par->mlx);
	free(par->mlx);
	free_map(par->map, par->width);
	free(par);
	return (1);
}

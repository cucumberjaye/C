/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/28 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_place_bonus(t_par *par, char map, int i, int j)
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
	if (map == 'V')
		mlx_put_image_to_window(par->mlx, par->win, par->e[0], j * 50, i * 50);
}

void	image_bonus(t_par *par)
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
	par->e[0] = mlx_xpm_file_to_image(par->mlx, "images/enemy1.xpm", &s, &s);
	par->e[1] = mlx_xpm_file_to_image(par->mlx, "images/enemy2.xpm", &s, &s);
	par->e[2] = mlx_xpm_file_to_image(par->mlx, "images/enemy3.xpm", &s, &s);
	par->e[3] = mlx_xpm_file_to_image(par->mlx, "images/enemy4.xpm", &s, &s);
}

int	sprite(t_par *p)
{
	int				i;
	int				j;
	static int		f = 0;
	int				a;
	int				b;

	i = 0;
	while (i < p->width)
	{
		j = 0;
		while (j < p->length)
		{
			a = i * 50;
			b = j * 50;
			if (p->map[i][j] == 'V' && f % 15000 == 0)
				mlx_put_image_to_window(p->mlx, p->win, p->e[f / 15000], b, a);
			++j;
		}
		++i;
	}
	if (f == 45000)
		f = -1;
	++f;
	return (1);
}

void	free_par_bonus(t_par *par)
{
	mlx_loop_end(par->mlx);
	mlx_destroy_image(par->mlx, par->i[0]);
	mlx_destroy_image(par->mlx, par->i[1]);
	mlx_destroy_image(par->mlx, par->i[2]);
	mlx_destroy_image(par->mlx, par->i[3]);
	mlx_destroy_image(par->mlx, par->i[4]);
	mlx_destroy_image(par->mlx, par->i[5]);
	mlx_destroy_image(par->mlx, par->i[6]);
	mlx_destroy_image(par->mlx, par->e[0]);
	mlx_destroy_image(par->mlx, par->e[1]);
	mlx_destroy_image(par->mlx, par->e[2]);
	mlx_destroy_image(par->mlx, par->e[3]);
	mlx_destroy_window(par->mlx, par->win);
	mlx_destroy_display(par->mlx);
	free(par->mlx);
	free_map(par->map, par->width);
}

int	move_bonus(t_par *par, int x, int y)
{
	par->x = x;
	par->y = y;
	if (par->map[par->pp[0] + x][par->pp[1] + y] != '1')
	{
		score_in_window(par);
		if (par->map[par->pp[0] + x][par->pp[1] + y] == 'C')
			--par->c;
		if (par->map[par->pp[0] + x][par->pp[1] + y] == 'E' && par->c == 0)
		{
			replace_img(par, 5, 0);
			return (1);
		}
		else if (par->map[par->pp[0] + x][par->pp[1] + y] == 'E' && par->c)
			replace_img(par, 5, 0);
		else if (par->map[par->pp[0]][par->pp[1]] == 'E')
			replace_img(par, 2, 4);
		else if (par->map[par->pp[0] + x][par->pp[1] + y] == 'V')
			return (game_over(par));
		else
			replace_img(par, 2, 0);
		par->pp[0] = par->pp[0] + x;
		par->pp[1] = par->pp[1] + y;
	}
	return (0);
}

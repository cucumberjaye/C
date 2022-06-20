/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/28 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	replace_img(t_par *par, int img1, int img2)
{
	char	*str;
	int		i;

	i = 0;
	mlx_put_image_to_window(par->mlx, par->win, par->i[img1],
		(par->pp[1] + par->y) * 50, (par->pp[0] + par->x) * 50);
	mlx_put_image_to_window(par->mlx, par->win, par->i[img2],
		par->pp[1] * 50, par->pp[0] * 50);
	if (par->map[par->pp[0] + par->x][par->pp[1] + par->y] == 'C')
	{
		str = (char *)malloc(sizeof(char) * par->length);
		while (i < par->length)
		{
			if (i == par->pp[1] + par->y)
				str[i] = '0';
			else
				str[i] = par->map[par->pp[0] + par->x][i];
			++i;
		}
		free(par->map[par->pp[0] + par->x]);
		par->map[par->pp[0] + par->x] = str;
	}
}

int	move(t_par *par, int x, int y)
{
	par->x = x;
	par->y = y;
	if (par->map[par->pp[0] + x][par->pp[1] + y] != '1')
	{
		++par->steps;
		ft_printf("%d\n", par->steps);
		if (par->map[par->pp[0] + x][par->pp[1] + y] == 'C')
			--par->c;
		if (par->map[par->pp[0] + x][par->pp[1] + y] == 'E' && par->c == 0)
		{
			replace_img(par, 5, 0);
			return (1);
		}
		else if (par->map[par->pp[0] + x][par->pp[1] + y] == 'E' && par->c != 0)
			replace_img(par, 5, 0);
		else if (par->map[par->pp[0]][par->pp[1]] == 'E')
			replace_img(par, 2, 4);
		else
			replace_img(par, 2, 0);
		par->pp[0] = par->pp[0] + x;
		par->pp[1] = par->pp[1] + y;
	}
	return (0);
}

int	keybord(int code, t_par *par)
{
	par->finish = 0;
	if (code == X_W)
		par->finish = move(par, -1, 0);
	if (code == X_S)
		par->finish = move(par, 1, 0);
	if (code == X_A)
		par->finish = move(par, 0, -1);
	if (code == X_D)
		par->finish = move(par, 0, 1);
	if (code == X_ESC)
		mlx_loop_end(par->mlx);
	if (par->finish == 1)
	{
		write(1, "Amazing!\n", 9);
		mlx_loop_end(par->mlx);
	}
	return (1);
}

int	mouse(t_par *par)
{
	exit(free_par(par));
	return (1);
}

void	play(t_par *par)
{
	mlx_key_hook(par->win, keybord, par);
	mlx_hook(par->win, 17, 1L << 17, mouse, par);
	mlx_loop(par->mlx);
}

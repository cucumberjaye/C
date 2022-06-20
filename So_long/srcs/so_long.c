/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/28 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_par	*par;

	if (argc != 2)
		return (write(2, "Invalid number of arguments\n", 28));
	par = (t_par *)malloc(sizeof(t_par));
	par->map = pars(argv[1], par);
	if (par->map == NULL)
		exit(1);
	if (errors(par->map, par) != 0)
		exit(free_map(par->map, par->width));
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, par->length * 50,
			par->width * 50, "so_long");
	textures(par);
	play(par);
	free_par(par);
	exit(0);
}

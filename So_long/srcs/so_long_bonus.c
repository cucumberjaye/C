/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/28 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	score_in_window(t_par *par)
{
	char	*str;
	char	*s2;
	void	*back;

	++par->steps;
	ft_printf("%d\n", par->steps);
	s2 = ft_itoa(par->steps);
	str = ft_strjoin("Score: ", s2);
	back = mlx_new_image(par->mlx, 100, 50);
	mlx_put_image_to_window(par->mlx, par->win, back, 0, par->width * 50);
	mlx_destroy_image(par->mlx, back);
	mlx_string_put(par->mlx, par->win, 10,
		par->width * 50 + 25, 25610000, str);
	free(s2);
	free(str);
}

int	keybord_bonus(int code, t_par *par)
{
	par->finish = 0;
	if (code == X_W)
		par->finish = move_bonus(par, -1, 0);
	if (code == X_S)
		par->finish = move_bonus(par, 1, 0);
	if (code == X_A)
		par->finish = move_bonus(par, 0, -1);
	if (code == X_D)
		par->finish = move_bonus(par, 0, 1);
	if (code == X_ESC)
		mlx_loop_end(par->mlx);
	if (par->finish == 2)
		mlx_loop_end(par->mlx);
	if (par->finish == 1)
	{
		write(1, "Amazing!\n", 9);
		mlx_loop_end(par->mlx);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_par	*par;

	if (argc != 2)
		return (write(2, "Invalid number of arguments\n", 28));
	par = (t_par *)malloc(sizeof(t_par));
	par->map = pars(argv[1], par);
	if (par->map == NULL)
		return (1);
	if (errors_bonus(par->map, par) != 0)
		return (1);
	par->mlx = mlx_init();
	par->win = mlx_new_window(par->mlx, par->length * 50,
			(par->width + 1) * 50, "so_long");
	mlx_string_put(par->mlx, par->win, 10, (par->width) * 50 + 25,
		25610000, "Score: 0");
	textures_bonus(par);
	play_bonus(par);
	free_par_bonus(par);
	free(par);
	return (1);
}

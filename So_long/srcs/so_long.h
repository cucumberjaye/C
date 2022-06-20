/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/28 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../getnl/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "../printf/ft_printf.h"

# define X_W 119
# define X_A 97
# define X_S 115
# define X_D 100
# define X_ESC 65307

typedef struct s_par
{
	int		length;
	int		width;
	int		c;
	int		exits;
	int		steps;
	int		player;
	int		x;
	int		y;
	int		finish;
	void	*mlx;
	void	*win;
	char	**map;
	void	*i[7];
	void	*e[4];
	int		pp[2];
}	t_par;

char	**pars(char *map, t_par *par);
int		errors(char **map, t_par *par);
void	textures(t_par *par);
void	play(t_par *par);
int		free_par(t_par *par);
char	*ft_itoa(int n);
void	score_in_window(t_par *par);
int		game_over(t_par *par);
int		sprite(t_par *par);
void	img_place_bonus(t_par *par, char map, int i, int j);
void	image_bonus(t_par *par);
void	free_par_bonus(t_par *par);
int		keybord(int code, t_par *par);
int		move(t_par *par, int x, int y);
void	replace_img(t_par *par, int img1, int img2);
int		mouse(t_par *par);
void	play_bonus(t_par *par);
void	textures_bonus(t_par *par);
int		contain(char **map, t_par *par);
int		errors_bonus(char **map, t_par *par);
int		free_map(char **map, int count);
void	player_place(t_par *par);
int		cep(char **map, t_par *par);
int		walls(char **map, t_par *par);
int		move_bonus(t_par *par, int x, int y);
int		move(t_par *par, int x, int y);
int		keybord_bonus(int code, t_par *par);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
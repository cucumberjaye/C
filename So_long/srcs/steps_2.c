/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:21:48 by cjaye             #+#    #+#             */
/*   Updated: 2022/03/28 16:22:01 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*j_str;
	size_t	i;
	size_t	j;

	j_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!j_str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		j_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		j_str[i] = s2[j];
		i++;
		j++;
	}
	j_str[i] = '\0';
	return (j_str);
}

int	game_over(t_par *par)
{
	mlx_put_image_to_window(par->mlx, par->win, par->i[6],
		par->pp[1] * 50, par->pp[0] * 50);
	write(1, "Game over\n", 10);
	return (2);
}

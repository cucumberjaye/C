/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:14:05 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/21 17:31:38 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	leng(char *s)
{
	unsigned int	l;

	l = 0;
	while (s[l])
		++l;
	return (l);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	l;
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	l = leng(s);
	while (i < l)
	{
		f(i, &s[i]);
		++i;
	}
}

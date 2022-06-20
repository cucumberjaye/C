/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:01:53 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/13 12:52:24 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		l;
	char	*new;

	l = 0;
	while (src[l])
		++l;
	new = (char *)malloc(sizeof(char) * l + 1);
	if (!new)
		return (NULL);
	l = 0;
	while (src[l])
	{
		new[l] = src[l];
		++l;
	}
	new[l] = '\0';
	return (new);
}

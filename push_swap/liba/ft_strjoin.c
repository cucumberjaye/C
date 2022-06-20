/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:26:38 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/22 18:00:22 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		l;
	int		k;
	char	*sub;

	if (!s1 || !s2)
		return (NULL);
	l = 0;
	k = 0;
	while (s1[l])
		++l;
	while (s2[k])
		++k;
	new = (char *)malloc(sizeof(char) * (l + k) + 1);
	if (!new)
		return (NULL);
	sub = new;
	while (*s1)
		*(new++) = *(s1++);
	while (*s2)
		*(new++) = *(s2++);
	*new = '\0';
	return (sub);
}

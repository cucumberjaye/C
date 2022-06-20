/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjaye <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:49:51 by cjaye             #+#    #+#             */
/*   Updated: 2021/10/16 15:20:52 by cjaye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*src;
	char	*s1;
	size_t	i;

	i = 0;
	src = (void *)malloc(size * num);
	if (!src)
		return (NULL);
	s1 = (char *)src;
	while (i < num * size)
		s1[i++] = '\0';
	return ((void *)s1);
}

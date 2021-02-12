/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 09:57:43 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/18 00:18:24 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*q;
	unsigned char	uc;

	i = 0;
	p = (unsigned char *)dest;
	q = (unsigned char *)src;
	uc = (unsigned char)c;
	while (i < n)
	{
		p[i] = q[i];
		if (p[i] == uc)
			return ((void *)p + i + 1);
		i++;
	}
	return (NULL);
}

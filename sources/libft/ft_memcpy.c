/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 09:53:23 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/18 00:17:26 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*p;
	char		*q;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (0);
	p = (char *)dest;
	q = (char *)src;
	i = 0;
	while (i < n)
	{
		p[i] = q[i];
		i++;
	}
	return (dest);
}

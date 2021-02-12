/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 10:12:00 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/17 14:52:39 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*q;

	if (s1 == s2 || n == 0)
		return (0);
	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	while (n--)
	{
		if (*p != *q)
			return (*p - *q);
		p++;
		q++;
	}
	return (0);
}

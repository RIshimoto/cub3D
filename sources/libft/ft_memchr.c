/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 10:07:17 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/17 14:33:54 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	char	uc;

	p = (char *)s;
	uc = (char)c;
	while (n--)
	{
		if (*p == uc)
			return (p);
		p++;
	}
	return (0);
}

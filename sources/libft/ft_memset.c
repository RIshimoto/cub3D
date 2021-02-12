/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 03:41:53 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/17 14:33:04 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*p;
	char	uc;

	i = 0;
	p = (char *)s;
	uc = (char)c;
	while (i < n)
	{
		p[i] = uc;
		i++;
	}
	return (s);
}

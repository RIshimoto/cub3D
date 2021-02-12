/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:53:37 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/17 14:56:27 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*q;

	i = 0;
	p = (unsigned char *)s1;
	q = (unsigned char *)s2;
	while (i < n)
	{
		if (p[i] != q[i] || p[i] == '\0' || q[i] == '\0')
			return (p[i] - q[i]);
		i++;
	}
	return (0);
}

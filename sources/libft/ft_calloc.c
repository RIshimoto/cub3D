/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:08:46 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/18 00:14:52 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	n;

	n = nmemb * size;
	if (size && nmemb != n / size)
		return (0);
	if (!(p = malloc(n)))
		return (0);
	ft_memset(p, 0, n);
	return (p);
}

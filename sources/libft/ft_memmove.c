/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 10:03:53 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/11 20:20:39 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (0);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			*((char *)dest + n) = *((char *)src + n);
	}
	return (dest);
}

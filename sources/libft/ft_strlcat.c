/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 02:27:01 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/11 15:49:20 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	len = dest_len + src_len;
	if (size <= dest_len)
		return (src_len + size);
	while (*dest)
		dest++;
	i = 0;
	while (i < size - dest_len - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

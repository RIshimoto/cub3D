/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:39:13 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/11 21:56:16 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (i + j <= len && little[j])
			{
				if (big[i + j] != little[j])
					break ;
				j++;
			}
			if (!little[j])
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}

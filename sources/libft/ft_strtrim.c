/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:24:22 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/16 16:09:27 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*p;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strrchr(set, s1[end]) && end >= 0)
		end--;
	while (ft_strrchr(set, s1[start]) && start < end)
		start++;
	if (start >= end)
	{
		if (!(p = ft_strdup("")))
			return (0);
		return (p);
	}
	if (!(p = ft_substr(s1, start, end - start + 1)))
		return (NULL);
	return (p);
}

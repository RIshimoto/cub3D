/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:36:26 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/16 16:09:04 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
	{
		if (!(t = ft_strdup("")))
			return (NULL);
		return (t);
	}
	if (!(t = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	i = 0;
	while (i < len)
	{
		t[i] = s[start];
		i++;
		start++;
	}
	t[i] = '\0';
	return (t);
}

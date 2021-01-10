/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 01:19:18 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/13 01:00:31 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_join(char const *s, char *t, int index)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		t[index] = s[i];
		i++;
		index++;
	}
	return (index);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	size_t	len;
	size_t	index;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	t = (char *)malloc((len + 1) * sizeof(char));
	if (t == NULL)
		return (0);
	index = ft_join(s1, t, 0);
	index = ft_join(s2, t, index);
	t[index] = '\0';
	return (t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 12:40:58 by rishimot          #+#    #+#             */
/*   Updated: 2020/12/25 10:31:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_cnt_words(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			while (s[i] == c && s[i])
				i++;
	}
	return (len);
}

static int		skip_str(char const *s, char c, int index)
{
	int len;

	len = 0;
	while (s[index + len] != c && s[index + len])
		len++;
	return (len);
}

static char		**all_free(char ***p, int j)
{
	while (j >= 0)
	{
		free((*p)[j]);
		(*p)[j] = NULL;
		j--;
	}
	free(*p);
	*p = NULL;
	return (0);
}

static char		**ft_split_main(char const *s, char c)
{
	size_t	len;
	char	**p;
	int		now;
	int		j;

	if (!(p = (char **)malloc(sizeof(char *) * (ft_cnt_words(s, c) + 1))))
		return (0);
	j = 0;
	now = 0;
	while (s[now])
	{
		while (s[now] == c && s[now])
			now++;
		if (!s[now])
			break ;
		len = skip_str(s, c, now);
		if (!(p[j] = ft_substr(s, now, len)))
			return (all_free(&p, j - 1));
		j++;
		now += len;
	}
	p[j] = NULL;
	return (p);
}

char			**ft_split(char const *s, char c)
{
	char	**p;

	if (s == NULL)
		return (0);
	if (!c && !(*s))
	{
		if (!(p = (char **)malloc(sizeof(char *))))
			return (0);
		p[0] = NULL;
		return (p);
	}
	p = ft_split_main(s, c);
	return (p);
}

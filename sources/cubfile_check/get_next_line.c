/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:36:30 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 06:59:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

static char		*ft_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (str);
}

static void		ft_memmove(char *s, char *t)
{
	int i;

	i = 0;
	while (t[i] != '\0')
	{
		s[i] = t[i];
		i++;
	}
	s[i] = '\0';
}

static char		*ft_strjoin(char *s1, char *s2, int s2_len)
{
	int		s1_len;
	int		s3_len;
	int		i;
	int		j;
	char	*s3;

	s1_len = ft_strchr(s1, '\0') - s1;
	s3_len = s1_len + s2_len;
	if ((s3 = (char *)malloc(sizeof(char) * (s3_len + 1))) == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (i < s1_len)
		s3[j++] = s1[i++];
	i = 0;
	while (i < s2_len)
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}

static int		get_line(int fd, char *buf, char **line)
{
	char	*p;
	char	*tmp;
	int		len;

	p = ft_strchr(buf, '\n');
	tmp = *line;
	*line = ft_strjoin(*line, buf, p - buf);
	free(tmp);
	if (*line == NULL)
		return (ERROR);
	if (*p == '\n')
	{
		ft_memmove(buf, p + 1);
		return (SUCESS);
	}
	if ((len = read(fd, buf, 1000)) < 0)
		return (ERROR);
	buf[len] = '\0';
	if (len == 0)
		return (*line[0] == '\0' ? END : SUCESS);
	return (get_line(fd, buf, line));
}

int				get_next_line(int fd, char **line)
{
	static char buf[1024];

	if ((*line = malloc(1)) == NULL || fd < 0 || fd == 1 || fd == 2)
		return (ERROR);
	*line[0] = '\0';
	return (get_line(fd, buf, line));
}

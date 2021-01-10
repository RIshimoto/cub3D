/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_each_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 06:24:34 by user42            #+#    #+#             */
/*   Updated: 2021/01/09 08:02:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void		map_resize(t_info *p)
{
	char	**m;
	int		i;
	int		j;

	m = (char **)malloc(sizeof(char *) * p->map_height);
	i = -1;
	while (++i < p->map_height)
	{
		m[i] = (char *)malloc(sizeof(char) * p->map_width);
		ft_memset(m[i], ' ', p->map_width);
		j = 0;
		while (p->map[i][j] != '\0')
		{
			m[i][j] = p->map[i][j];
			j++;
		}
		free(p->map[i]);
	}
	free(p->map);
	p->map = m;
}

static char		**store_map(char *add_line, t_info *p)
{
	char	**new;
	int		i;

	p->visited |= MAP_FLAG;
	new = (char **)malloc(sizeof(char *) * (p->map_height + 1));
	i = -1;
	while (++i < p->map_height)
		new[i] = p->map[i];
	free(p->map);
	new[i] = add_line;
	p->map_width = max(p->map_width, (int)ft_strlen(add_line));
	p->map_height++;
	return (new);
}

static char		is_space(char *line)
{
	while (*line == ' ')
		line++;
	return (*line);
}

static void		check_identify(char *line, t_info *p)
{
	if (!ft_strncmp(line, "R", 1))
		check_identify_r(line, p);
	else if (!ft_strncmp(line, "NO", 2))
		check_identify_no(line, p);
	else if (!ft_strncmp(line, "SO", 2))
		check_identify_so(line, p);
	else if (!ft_strncmp(line, "WE", 2))
		check_identify_we(line, p);
	else if (!ft_strncmp(line, "EA", 2))
		check_identify_ea(line, p);
	else if (!ft_strncmp(line, "S", 1))
		check_identify_s(line, p);
	else if (!ft_strncmp(line, "F", 1))
		check_identify_f(line, p);
	else if (!ft_strncmp(line, "C", 1))
		check_identify_c(line, p);
	else if (ft_isdigit(is_space(line)))
		p->map = store_map(line, p);
	else
	{
		error("Invalid identify", p);
		free(line);
	}
}

void			fetch_each_line(int fd, t_info *p)
{
	char		*line;
	int			gnl;

	while (0 < (gnl = get_next_line(fd, &line)))
	{
		if (line[0] == '\0')
		{
			if (p->visited & MAP_FLAG)
				error("Map is end of file!", p);
			free(line);
			continue ;
		}
		check_identify(line, p);
	}
	free(line);
	map_resize(p);
}

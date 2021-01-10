/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:30:38 by user42            #+#    #+#             */
/*   Updated: 2021/01/07 04:11:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void			error(char *s, t_info *p)
{
	write(2, &"Error\n", 6);
	write(2, s, ft_strlen(s));
	write(2, &"\n", 1);
	p->valid = false;
}

bool			check_file_name(t_info *p, char *file, char *extention)
{
	int i;
	int	len;

	if (file == NULL)
		return (false);
	len = ft_strlen(file);
	i = -1;
	while (++i < 4)
	{
		if (file[len - i - 1] == extention[3 - i])
			continue ;
		error("wrong file name", p);
		return (false);
	}
	return (true);
}

static void		file_info_init(t_info *p)
{
	p->visited = 0;
	p->win_w = 0;
	p->win_h = 0;
	p->floor_rgb = 0;
	p->celling_rgb = 0;
	p->tex_path = (char **)malloc(sizeof(char *) * 5);
	p->texture_cnt = 5;
	p->sprite_cnt = 0;
	p->map = (char **)malloc(sizeof(char*) * 1);
	p->map[0] = NULL;
	p->map_height = 0;
	p->map_width = 0;
	p->map_start_x = 0;
	p->map_start_y = 0;
	p->valid = true;
}

static bool		check_file_content(t_info *p)
{
	int			i;

	i = -1;
	while (++i <= 8)
	{
		if (!(p->visited & (1 << i)))
		{
			error("The cub file is invalid", p);
			return (false);
		}
	}
	return (true);
}

void			file_error_check(char *file_name, t_info *p)
{
	int fd;

	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		error("Could not open file", p);
		exit(1);
	}
	file_info_init(p);
	check_file_name(p, file_name, ".cub");
	fetch_each_line(fd, p);
	check_file_content(p);
	check_map_char(p);
	check_map_closed(p);
	close(fd);
	if (!p->valid)
	{
		all_free(p);
		exit(0);
	}
}

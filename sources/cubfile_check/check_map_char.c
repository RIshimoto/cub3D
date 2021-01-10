/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:19:39 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 10:01:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void		check_map_sprite_cnt(t_info *p)
{
	int		i;
	int		j;

	i = -1;
	while (++i < p->map_height)
	{
		j = -1;
		while (++j < p->map_width)
		{
			if (p->map[i][j] == '2')
				p->sprite_cnt++;
		}
	}
	p->sprite = (t_sprite *)malloc(sizeof(t_sprite) * p->sprite_cnt);
	p->sprite_cnt = 0;
}

static void		check_map_start_pos(t_info *p)
{
	bool	find_start_pos;
	int		i;
	int		j;

	find_start_pos = false;
	i = -1;
	while (++i < p->map_height)
	{
		j = -1;
		while (++j < p->map_width)
			if ((p->map[i][j] == 'N' || p->map[i][j] == 'E' ||\
				p->map[i][j] == 'S' || p->map[i][j] == 'W'))
			{
				if (find_start_pos)
					error("Map must have only one start pos", p);
				find_start_pos = true;
				p->map_start_dist = p->map[i][j];
				p->map_start_x = i;
				p->map_start_y = j;
				p->map[i][j] = '0';
			}
	}
	if (!find_start_pos)
		error("Could not find start pos", p);
}

static void		check_map_irregular_char(t_info *p)
{
	int		i;
	int		j;

	i = -1;
	while (++i < p->map_height)
	{
		j = -1;
		while (++j < p->map_width)
		{
			if (p->map[i][j] == ' ')
				p->map[i][j] = '0';
			if (!((ft_strchr("NESW", p->map[i][j])) ||\
				('0' <= p->map[i][j] && p->map[i][j] <= '2')))
				error("Invalid char", p);
		}
	}
}

void			check_map_char(t_info *p)
{
	check_map_start_pos(p);
	check_map_irregular_char(p);
	check_map_sprite_cnt(p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:41:41 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 12:41:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	celling_and_flooring(t_info *info)
{
	int	x;
	int	y;

	x = 0;
	while (x < info->win_w)
	{
		y = 0;
		while (y < info->win_h)
		{
			if (y * 2 < info->win_h)
				info->buf[y][x] = info->floor_rgb;
			else
				info->buf[y][x] = info->celling_rgb;
			y++;
		}
		x++;
	}
}

void	calc(t_info *info)
{
	celling_and_flooring(info);
	wall(info);
	sprite(info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:42:14 by user42            #+#    #+#             */
/*   Updated: 2021/01/07 04:41:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			draw(t_info *info)
{
	int x;
	int y;

	y = -1;
	while (++y < info->win_h)
	{
		x = -1;
		while (++x < info->win_w)
			info->img.data[y * info->win_w + x] = info->buf[y][x];
	}
}

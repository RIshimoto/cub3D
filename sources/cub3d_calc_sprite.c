/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_calc_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:41:31 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 13:35:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		swap(t_info *info, double *dist, int j)
{
	double		tmpd;
	t_sprite	tmps;

	tmpd = dist[j];
	dist[j] = dist[j + 1];
	dist[j + 1] = tmpd;
	tmps = info->sprite[j];
	info->sprite[j] = info->sprite[j + 1];
	info->sprite[j + 1] = tmps;
}

static void		sort_order(t_info *info)
{
	int		i;
	int		j;
	double	dist[info->sprite_cnt];

	i = -1;
	while (++i < info->sprite_cnt)
	{
		dist[i] = ((info->pos_x - info->sprite[i].x)
				* (info->pos_x - info->sprite[i].x)
				+ (info->pos_y - info->sprite[i].y)
				* (info->pos_y - info->sprite[i].y));
	}
	i = -1;
	while (++i < info->sprite_cnt)
	{
		j = -1;
		while (++j < info->sprite_cnt - 1)
			if (dist[j] < dist[j + 1])
				swap(info, dist, j);
	}
}

static void		sprite_draw_pos(t_info *info, t_sp_info *sp_info)
{
	sp_info->h = (int)fabs((info->win_h / sp_info->trans_y) / VDIV);
	sp_info->draw_start_y = (info->win_h - sp_info->h) / 2 + sp_info->vms;
	if (sp_info->draw_start_y < 0)
		sp_info->draw_start_y = 0;
	sp_info->draw_end_y = sp_info->h / 2 + info->win_h / 2 + sp_info->vms;
	if (sp_info->draw_end_y > info->win_h)
		sp_info->draw_end_y = info->win_h - 1;
	sp_info->w = (int)fabs((info->win_h / sp_info->trans_y) / UDIV);
	sp_info->draw_start_x = -sp_info->w / 2 + sp_info->screen_x;
	if (sp_info->draw_start_x < 0)
		sp_info->draw_start_x = 0;
	sp_info->draw_end_x = sp_info->w / 2 + sp_info->screen_x;
	if (sp_info->draw_end_x > info->win_w)
		sp_info->draw_end_x = info->win_w - 1;
}

void			sprite_draw(t_info *info, t_sp_info *sp_info)
{
	int		x;
	int		y;
	int		d;
	int		color;

	x = sp_info->draw_start_x - 1;
	while (++x < sp_info->draw_end_x)
	{
		sp_info->tex_x = (int)((256 * (x - (-sp_info->w / 2
		+ sp_info->screen_x)) * info->tex[4].w / sp_info->w) / 256);
		if (sp_info->trans_y > 0 && x > 0 &&\
			x < info->win_w && sp_info->trans_y < info->buffer[x])
		{
			y = sp_info->draw_start_y - 1;
			while (++y < sp_info->draw_end_y)
			{
				d = (y - sp_info->vms) * 256 - (info->win_h - sp_info->h) * 128;
				sp_info->tex_y = ((d * info->tex[4].h) / sp_info->h) / 256;
				d = info->tex[4].w * sp_info->tex_y + sp_info->tex_x;
				color = info->tex[4].tex[d];
				if ((color & 0x00FFFFFF) != 0)
					info->buf[y][x] = color;
			}
		}
	}
}

void			sprite(t_info *info)
{
	t_sp_info		sp_info;
	int				i;

	sort_order(info);
	i = -1;
	while (++i < info->sprite_cnt)
	{
		sp_info.x = info->sprite[i].x - info->pos_x;
		sp_info.y = info->sprite[i].y - info->pos_y;
		sp_info.inv = \
		1.0 / (info->plane_x * info->dir_y - info->dir_x * info->plane_y);
		sp_info.trans_x = sp_info.inv
			* (info->dir_y * sp_info.x - info->dir_x * sp_info.y);
		sp_info.trans_y = \
		sp_info.inv * (-info->plane_y * sp_info.x + info->plane_x * sp_info.y);
		sp_info.screen_x = (int)((info->win_w / 2) *
			(1 + sp_info.trans_x / sp_info.trans_y));
		sp_info.vms = (int)(VMOVE / sp_info.trans_y);
		sprite_draw_pos(info, &sp_info);
		sprite_draw(info, &sp_info);
	}
}

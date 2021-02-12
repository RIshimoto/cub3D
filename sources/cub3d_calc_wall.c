/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_calc_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:41:53 by user42            #+#    #+#             */
/*   Updated: 2021/01/07 02:11:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	wall_texture(t_info *info, t_wall_tex *wall_tex, t_ray *ray)
{
	double wall_x;

	if (ray->side == 0 && ray->raydir_x < 0)
		wall_tex->no = 0;
	else if (ray->side == 0 && ray->raydir_x > 0)
		wall_tex->no = 1;
	else if (ray->side == 1 && ray->raydir_y < 0)
		wall_tex->no = 2;
	else if (ray->side == 1 && ray->raydir_y > 0)
		wall_tex->no = 3;
	if (ray->side == 0)
		wall_x = info->pos_y + ray->perpwall_dist * ray->raydir_y;
	else
		wall_x = info->pos_x + ray->perpwall_dist * ray->raydir_x;
	wall_x -= floor((wall_x));
	wall_tex->x = (int)(wall_x * (double)info->tex[wall_tex->no].w);
	if (ray->side == 0 && ray->raydir_x > 0)
		wall_tex->x = info->tex[wall_tex->no].w - wall_tex->x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		wall_tex->x = info->tex[wall_tex->no].w - wall_tex->x - 1;
}

static void	wall_draw(t_info *info, t_ray *ray, int x)
{
	int			draw_start;
	int			draw_end;
	int			color;
	double		step;
	t_wall_tex	wall_tex;

	draw_start = max(-ray->line_height / 2 + info->win_h / 2, 0);
	draw_end = min(ray->line_height / 2 + info->win_h / 2,\
					info->win_h - 1);
	wall_texture(info, &wall_tex, ray);
	step = 1.0 * info->tex[wall_tex.no].h / ray->line_height;
	wall_tex.pos = \
	(draw_start - info->win_h / 2 + ray->line_height / 2) * step;
	while (draw_start++ < draw_end)
	{
		wall_tex.y =\
			(int)wall_tex.pos & (info->tex[wall_tex.no].h - 1);
		wall_tex.pos += step;
		color = info->tex[wall_tex.no].tex[
			info->tex[wall_tex.no].h * wall_tex.y + wall_tex.x];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		info->buf[draw_start][x] = color;
	}
	info->buffer[x] = ray->perpwall_dist;
}

static void	dda(t_info *info, t_ray *ray, int step_x, int step_y)
{
	while (info->map[ray->map_x][ray->map_y] != '1')
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += step_y;
			ray->side = 1;
		}
	}
	if (ray->side == 0)
		ray->perpwall_dist = \
		(ray->map_x - info->pos_x + (1 - step_x) / 2) / ray->raydir_x;
	else
		ray->perpwall_dist = \
		(ray->map_y - info->pos_y + (1 - step_y) / 2) / ray->raydir_y;
	ray->line_height = (int)(info->win_h / ray->perpwall_dist);
}

static void	ray_casting(t_info *info, t_ray *ray)
{
	int step_x;
	int step_y;

	if (ray->raydir_x < 0)
	{
		step_x = -1;
		ray->side_dist_x = (info->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - info->pos_x) * ray->delta_dist_x;
	}
	if (ray->raydir_y < 0)
	{
		step_y = -1;
		ray->side_dist_y = (info->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - info->pos_y) * ray->delta_dist_y;
	}
	dda(info, ray, step_x, step_y);
}

void		wall(t_info *info)
{
	double	camera_x;
	t_ray	ray;
	int		x;

	x = 0;
	while (x < info->win_w)
	{
		camera_x = 2 * x / (double)info->win_w - 1;
		ray.raydir_x = info->dir_x + info->plane_x * camera_x;
		ray.raydir_y = info->dir_y + info->plane_y * camera_x;
		ray.delta_dist_x = fabs(1 / ray.raydir_x);
		ray.delta_dist_y = fabs(1 / ray.raydir_y);
		ray.map_x = (int)info->pos_x;
		ray.map_y = (int)info->pos_y;
		ray_casting(info, &ray);
		wall_draw(info, &ray, x);
		x++;
	}
}

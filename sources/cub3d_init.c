/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 08:32:17 by user42            #+#    #+#             */
/*   Updated: 2021/01/07 08:16:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void				load_texture(t_info *info)
{
	t_img	img;
	int		i;
	int		x;
	int		y;

	i = -1;
	while (++i < 5)
	{
		img.img = mlx_xpm_file_to_image(info->mlx, info->tex_path[i],
										&img.img_w, &img.img_h);
		info->tex[i].h = img.img_h;
		info->tex[i].w = img.img_w;
		info->tex[i].tex = ft_calloc(sizeof(int), img.img_h * img.img_w);
		img.data = (int *)mlx_get_data_addr(img.img, &img.bpp,
											&img.size_l, &img.endian);
		y = -1;
		while (++y < img.img_h)
		{
			x = -1;
			while (++x < img.img_w)
				info->tex[i].tex[img.img_w * y + x] = \
				img.data[img.img_w * y + x];
		}
		mlx_destroy_image(info->mlx, img.img);
	}
}

static void			info_init_start_dist(t_info *info)
{
	info->dir_x = 0.0;
	info->dir_y = 0.0;
	info->plane_x = 0.0;
	info->plane_y = 0.0;
	if (info->map_start_dist == 'N')
	{
		info->dir_x = -1.0;
		info->plane_y = 0.66;
	}
	else if (info->map_start_dist == 'S')
	{
		info->dir_x = 1.0;
		info->plane_y = -0.66;
	}
	else if (info->map_start_dist == 'W')
	{
		info->dir_y = -1.0;
		info->plane_x = -0.66;
	}
	else if (info->map_start_dist == 'E')
	{
		info->dir_y = 1.0;
		info->plane_x = 0.66;
	}
}

void				info_init(t_info *info)
{
	int i;
	int	sizex;
	int sizey;

	info->mlx = mlx_init();
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_esc = 0;
	info->move_speed = 0.05;
	info->rot_speed = 0.01;
	mlx_get_screen_size(info->mlx, &sizex, &sizey);
	info->win_w = min(info->win_w, sizex);
	info->win_h = min(info->win_h, sizey);
	info->pos_x = info->map_start_x;
	info->pos_y = info->map_start_y;
	info_init_start_dist(info);
	info->tex = (t_texture *)malloc(sizeof(t_texture) * 5);
	info->buf = (int **)malloc(sizeof(int *) * info->win_h);
	info->buffer = (double *)malloc(sizeof(double) * info->win_w);
	i = -1;
	while (++i < info->win_h)
		info->buf[i] = (int *)ft_calloc(info->win_w, sizeof(int));
}

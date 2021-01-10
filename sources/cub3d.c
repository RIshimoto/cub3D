/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:43:24 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 06:56:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int			main_loop(t_info *info)
{
	calc(info);
	draw(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	key_update(info);
	return (0);
}

int					closer(t_info *info)
{
	int i;

	all_free(info);
	i = -1;
	while (++i < 5)
		free(info->tex[i].tex);
	free(info->tex);
	i = -1;
	while (++i < info->win_h)
		free(info->buf[i]);
	free(info->buf);
	free(info->buffer);
	mlx_destroy_display(info->mlx);
	exit(0);
}

int					main(int argc, char **argv)
{
	t_info		info;

	if (argc > 3)
	{
		error("too many argument", &info);
		return (0);
	}
	file_error_check(argv[1], &info);
	info_init(&info);
	load_texture(&info);
	info.img.img = mlx_new_image(info.mlx, info.win_w, info.win_h);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp,\
	&info.img.size_l, &info.img.endian);
	if (argc == 3)
		write_bmp(&info, argv[2]);
	info.win = mlx_new_window(info.mlx, info.win_w, info.win_h, "mlx");
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 1L << 1, &key_release, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 1L << 17, &closer, &info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_loop(info.mlx);
	return (0);
}

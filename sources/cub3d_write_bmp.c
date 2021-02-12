/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_write_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 04:43:32 by user42            #+#    #+#             */
/*   Updated: 2021/01/10 06:57:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/bitmap.h"

static void		bmp_file_header(t_info *info, t_bmp_info *bmp)
{
	bmp->real_width = info->win_w * 3 + info->win_w % 4;
	bmp->file_size = info->win_h * bmp->real_width + HEADERSIZE;
	bmp->offset_to_data = HEADERSIZE;
	bmp->info_header_size = INFOHEADERSIZE;
	bmp->planes = 1;
	bmp->color = 24;
	bmp->compress = 0;
	bmp->data_size = info->win_h * bmp->real_width;
	bmp->xppm = 1;
	bmp->yppm = 1;
	bmp->header_buf[0] = 'B';
	bmp->header_buf[1] = 'M';
	ft_memcpy(bmp->header_buf + 2, &bmp->file_size, sizeof(bmp->file_size));
	bmp->header_buf[6] = 0;
	bmp->header_buf[7] = 0;
	bmp->header_buf[8] = 0;
	bmp->header_buf[9] = 0;
	ft_memcpy(bmp->header_buf + 10, &bmp->offset_to_data,\
	sizeof(bmp->file_size));
	bmp->header_buf[11] = 0;
	bmp->header_buf[12] = 0;
	bmp->header_buf[13] = 0;
}

static void		bmp_info_header(t_info *info, t_bmp_info *bmp)
{
	ft_memcpy(bmp->header_buf + 14, &bmp->info_header_size, \
	sizeof(bmp->info_header_size));
	bmp->header_buf[15] = 0;
	bmp->header_buf[16] = 0;
	bmp->header_buf[17] = 0;
	ft_memcpy(bmp->header_buf + 18, &info->win_w, sizeof(info->win_w));
	ft_memcpy(bmp->header_buf + 22, &info->win_h, sizeof(info->win_h));
	ft_memcpy(bmp->header_buf + 26, &bmp->planes, sizeof(bmp->planes));
	ft_memcpy(bmp->header_buf + 28, &bmp->color, sizeof(bmp->color));
	ft_memcpy(bmp->header_buf + 30, &bmp->compress, sizeof(bmp->compress));
	ft_memcpy(bmp->header_buf + 34, &bmp->data_size, sizeof(bmp->data_size));
	ft_memcpy(bmp->header_buf + 38, &bmp->xppm, sizeof(bmp->xppm));
	ft_memcpy(bmp->header_buf + 42, &bmp->yppm, sizeof(bmp->yppm));
	bmp->header_buf[46] = 0;
	bmp->header_buf[47] = 0;
	bmp->header_buf[48] = 0;
	bmp->header_buf[49] = 0;
	bmp->header_buf[50] = 0;
	bmp->header_buf[51] = 0;
	bmp->header_buf[52] = 0;
}

static void		bmp_color_set(t_info *info, t_bmp_info *bmp, int fd)
{
	int			i;
	int			j;
	int			rgb;

	i = -1;
	while (++i < info->win_h)
	{
		j = -1;
		while (++j < info->win_w)
		{
			rgb = info->img.data[(info->win_h - i - 1) * info->win_w + j];
			bmp->bmp_line_data[j * 3] = (rgb & 0x0000FF);
			bmp->bmp_line_data[j * 3 + 1] = ((rgb & 0x00FF00) >> 8);
			bmp->bmp_line_data[j * 3 + 2] = ((rgb & 0xFF0000) >> 16);
		}
		j = info->win_w * 3 - 1;
		while (++j < bmp->real_width)
			bmp->bmp_line_data[j] = 0;
		write(fd, bmp->bmp_line_data, bmp->real_width);
	}
	free(bmp->bmp_line_data);
}

void			write_bmp(t_info *info, char *arg)
{
	int			fd;
	t_bmp_info	bmp;

	if (ft_strncmp(arg, "--save", ft_strlen(arg)) != 0)
	{
		ft_putstr_fd("Error\nThe second param is --save.", 2);
		exit(0);
	}
	if ((fd = open("save.bmp", O_WRONLY | O_CREAT, S_IRWXU)) < 0)
	{
		ft_putstr_fd("Error\nsave.bmp could not open.", 2);
		exit(1);
	}
	calc(info);
	draw(info);
	bmp_file_header(info, &bmp);
	bmp_info_header(info, &bmp);
	write(fd, bmp.header_buf, HEADERSIZE);
	if (!(bmp.bmp_line_data = malloc(sizeof(unsigned char) * bmp.real_width)))
	{
		ft_putstr_fd("Error: Allocation error.\n", 2);
		exit(1);
	}
	bmp_color_set(info, &bmp, fd);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:42:23 by user42            #+#    #+#             */
/*   Updated: 2021/01/06 23:35:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		key_update2(t_info *info)
{
	double old_dir_x;
	double old_plane_x;
	double theta;

	theta = 0;
	if (info->key_d)
		theta = -info->rot_speed;
	if (info->key_a)
		theta = info->rot_speed;
	old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(theta) - info->dir_y * sin(theta);
	info->dir_y = old_dir_x * sin(theta) + info->dir_y * cos(theta);
	old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(theta) - info->plane_y * sin(theta);
	info->plane_y = old_plane_x * sin(theta) + info->plane_y * cos(theta);
}

void			key_update(t_info *info)
{
	double next_pos_x;
	double next_pos_y;

	if (info->key_esc)
		closer(info);
	if (info->key_w)
	{
		next_pos_x = info->pos_x + info->dir_x * info->move_speed;
		next_pos_y = info->pos_y + info->dir_y * info->move_speed;
		if (info->map[(int)(next_pos_x)][(int)(info->pos_y)] == '0')
			info->pos_x = next_pos_x;
		if (info->map[(int)(info->pos_x)][(int)(next_pos_y)] == '0')
			info->pos_y = next_pos_y;
	}
	if (info->key_s)
	{
		next_pos_x = info->pos_x - info->dir_x * info->move_speed;
		next_pos_y = info->pos_y - info->dir_y * info->move_speed;
		if (info->map[(int)(next_pos_x)][(int)(info->pos_y)] == '0')
			info->pos_x = next_pos_x;
		if (info->map[(int)(info->pos_x)][(int)(next_pos_y)] == '0')
			info->pos_y = next_pos_y;
	}
	key_update2(info);
}

int				key_press(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W || key == K_UP)
		info->key_w = 1;
	else if (key == K_A || key == K_LEFT)
		info->key_a = 1;
	else if (key == K_S || key == K_DOWN)
		info->key_s = 1;
	else if (key == K_D || key == K_RIGHT)
		info->key_d = 1;
	return (0);
}

int				key_release(int key, t_info *info)
{
	if (key == K_ESC)
	{
		all_free(info);
		exit(0);
	}
	else if (key == K_W || key == K_UP)
		info->key_w = 0;
	else if (key == K_A || key == K_LEFT)
		info->key_a = 0;
	else if (key == K_S || key == K_DOWN)
		info->key_s = 0;
	else if (key == K_D || key == K_RIGHT)
		info->key_d = 0;
	return (0);
}

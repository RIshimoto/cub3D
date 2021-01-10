/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:39:05 by user42            #+#    #+#             */
/*   Updated: 2021/01/07 08:09:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "key_macos.h"
# include "get_next_line.h"
# include "libft.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>

# define MAP_FLAG 1
# define NO_FLAG 2
# define SO_FLAG 4
# define WE_FLAG 8
# define EA_FLAG 16
# define S_FLAG 32
# define C_FLAG 64
# define F_FLAG 128
# define R_FLAG 256
# define SUCESS 1
# define END 0
# define ERROR -1
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 33
# define UDIV 1
# define VDIV 1
# define VMOVE 0.0
# define QSIZE 1000000
# define HASHSIZE 299993

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				img_w;
	int				img_h;
}					t_img;

typedef	struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_sp_info
{
	double			x;
	double			y;
	double			trans_x;
	double			trans_y;
	double			inv;
	int				screen_x;
	int				vms;
	int				h;
	int				w;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				tex_y;
}					t_sp_info;

typedef	struct		s_texture
{
	int				w;
	int				h;
	int				*tex;
}					t_texture;

typedef struct		s_info
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	void			*mlx;
	void			*win;
	int				key_a;
	int				key_w;
	int				key_s;
	int				key_d;
	int				key_esc;
	t_img			img;
	int				**buf;
	double			*buffer;
	t_texture		*tex;
	double			move_speed;
	double			rot_speed;

	int				visited;
	int				win_w;
	int				win_h;
	int				floor_rgb;
	int				celling_rgb;
	char			**tex_path;
	int				texture_cnt;
	t_sprite		*sprite;
	int				sprite_cnt;
	char			**map;
	char			map_start_dist;
	int				map_start_x;
	int				map_start_y;
	int				map_height;
	int				map_width;
	bool			valid;
}					t_info;

typedef	struct		s_state
{
	int				x;
	int				y;
	struct s_state	*hash_link;
}					t_state;

typedef struct		s_ray
{
	double			raydir_x;
	double			raydir_y;
	int				side;
	int				map_x;
	int				map_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perpwall_dist;
	int				line_height;
}					t_ray;

typedef struct		s_wall_texture
{
	int				x;
	int				y;
	double			pos;
	int				no;
}					t_wall_tex;

void				file_error_check(char *file_name, t_info *p);
void				check_identify_r(char *line, t_info *p);
void				check_identify_no(char *line, t_info *p);
void				check_identify_so(char *line, t_info *p);
void				check_identify_we(char *line, t_info *p);
void				check_identify_ea(char *line, t_info *p);
void				check_identify_s(char *line, t_info *p);
void				check_identify_f(char *line, t_info *p);
void				check_identify_c(char *line, t_info *p);
void				check_map_closed(t_info *p);
void				check_map_char(t_info *p);
void				fetch_each_line(int fd, t_info *p);
void				error(char *s, t_info *p);
void				dp_free(char **dp);
void				tab_free(char **dp, int n);
void				all_free(t_info *p);
bool				check_file_name(t_info *p, char *file, char *extention);
void				draw(t_info *info);
void				key_update(t_info *info);
int					key_press(int key, t_info *info);
int					key_release(int key, t_info *info);
void				calc(t_info *info);
void				sprite(t_info *info);
void				wall(t_info *info);
void				info_init(t_info *info);
int					closer(t_info *info);
void				write_bmp(t_info *info, char *arg);
int					max(int a, int b);
int					min(int a, int b);

void				load_texture(t_info *info);

#endif

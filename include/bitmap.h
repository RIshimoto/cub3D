/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:28:26 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 18:28:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# define FILEHEADERSIZE 14
# define INFOHEADERSIZE 40
# define HEADERSIZE 54

# include <stdlib.h>

typedef struct		s_bmp_info
{
	int				real_width;
	unsigned char	header_buf[HEADERSIZE];
	unsigned char	*bmp_line_data;
	unsigned int	file_size;
	unsigned int	offset_to_data;
	unsigned long	info_header_size;
	unsigned int	planes;
	unsigned int	color;
	unsigned long	compress;
	unsigned long	data_size;
	long			xppm;
	long			yppm;
}					t_bmp_info;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identify_rfc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 09:13:35 by user42            #+#    #+#             */
/*   Updated: 2021/01/04 08:19:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void			check_identify_r(char *line, t_info *p)
{
	int		i;
	int		num;
	char	**str;

	if (p->visited & R_FLAG || p->visited & MAP_FLAG)
		error("R: The identify is crazy", p);
	p->visited |= R_FLAG;
	str = ft_split(line, ' ');
	if (ft_strncmp(str[0], "R", ft_strlen(str[0])) != 0)
		error("R: Invalid identify", p);
	i = 0;
	while (str[++i] != NULL)
	{
		num = ft_atoi(str[i]);
		if (num < 0 || (ft_keta(num) != (int)ft_strlen(str[i])))
			error("R: Invalid num", p);
		p->win_w = (i == 1 ? num : p->win_w);
		p->win_h = (i == 2 ? num : p->win_h);
	}
	if (i != 3)
		error("R: Crazy element number", p);
	free(line);
	dp_free(str);
}

static void		check_comma_cnt(char **str, t_info *p)
{
	int	i;
	int	comma_cnt;

	i = -1;
	comma_cnt = 0;
	while (str[1][++i] != '\0')
	{
		if (str[1][i] == ',')
			comma_cnt++;
	}
	if (comma_cnt > 2)
		error("Too many commma", p);
}

static int		rgb_value(t_info *p, char *v)
{
	int num;

	num = ft_atoi(v);
	if (!(0 <= num && num < 256))
	{
		error("Out of color range", p);
		return (0);
	}
	if (ft_keta(num) != (int)ft_strlen(v))
		error("invalid num", p);
	return (num);
}

void			check_identify_f(char *line, t_info *p)
{
	int		i;
	char	**rgb;
	char	**str;

	if (p->visited & F_FLAG || p->visited & MAP_FLAG)
		error("F: The identify is crazy", p);
	p->visited |= F_FLAG;
	str = ft_split(line, ' ');
	if (ft_strncmp(str[0], "F", ft_strlen(str[0])) != 0)
		error("F: Invalid identify", p);
	if (str[1] == NULL || str[2] != NULL)
		error("F: The number of element is crazy.", p);
	if (str[1] != NULL)
	{
		check_comma_cnt(str, p);
		rgb = ft_split(str[1], ',');
		i = -1;
		while (rgb[++i] != NULL)
			p->floor_rgb = (p->floor_rgb << 8) + rgb_value(p, rgb[i]);
		if (i != 3)
			error("F: Invalid RGB value", p);
		dp_free(rgb);
	}
	free(line);
	dp_free(str);
}

void			check_identify_c(char *line, t_info *p)
{
	int		i;
	char	**str;
	char	**rgb;

	if ((p->visited & C_FLAG) || (p->visited & MAP_FLAG))
		error("C: The identify is crazy", p);
	p->visited |= C_FLAG;
	str = ft_split(line, ' ');
	if (ft_strncmp(str[0], "C", ft_strlen(str[0])) != 0)
		error("C: Invalid identify", p);
	if (str[1] == NULL || str[2] != NULL)
		error("C: The number of element is crazy.", p);
	if (str[1] != NULL)
	{
		check_comma_cnt(str, p);
		rgb = ft_split(str[1], ',');
		i = -1;
		while (rgb[++i] != NULL)
			p->celling_rgb = (p->celling_rgb << 8) + rgb_value(p, rgb[i]);
		if (i != 3)
			error("C: Invalid RGB value", p);
		dp_free(rgb);
	}
	free(line);
	dp_free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identify_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:16:27 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 17:59:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_identify_no(char *line, t_info *p)
{
	char **str;

	if ((p->visited & NO_FLAG) || (p->visited & MAP_FLAG))
	{
		error("NO: The identify is crazy", p);
		free(line);
		return ;
	}
	p->visited |= NO_FLAG;
	str = ft_split(line, ' ');
	if (ft_strncmp(str[0], "NO", ft_strlen(str[0])) != 0)
		error("NO: Invalid identify", p);
	if (str[1] == NULL || str[2] != NULL)
		error("NO: Crazy number of elements", p);
	if (str[1] != NULL && open(str[1], O_RDONLY) < 0)
		error("NO: Irregular pass", p);
	if (check_file_name(p, str[1], ".xpm"))
		p->tex_path[0] = ft_strdup(str[1]);
	else
		p->visited &= ~NO_FLAG;
	dp_free(str);
	free(line);
}

void	check_identify_so(char *line, t_info *p)
{
	char **str;

	if ((p->visited & SO_FLAG) || (p->visited & MAP_FLAG))
	{
		error("SO: The identify is crazy", p);
		free(line);
		return ;
	}
	p->visited |= SO_FLAG;
	str = ft_split(line, ' ');
	if (ft_strncmp(str[0], "SO", ft_strlen(str[0])) != 0)
		error("SO: Invalid identify", p);
	if (str[1] == NULL || str[2] != NULL)
		error("SO: Crazy number of elements", p);
	if (str[1] != NULL && open(str[1], O_RDONLY) < 0)
		error("SO: Irregular pass", p);
	if (check_file_name(p, str[1], ".xpm"))
		p->tex_path[1] = ft_strdup(str[1]);
	else
		p->visited &= ~SO_FLAG;
	dp_free(str);
	free(line);
}

void	check_identify_we(char *line, t_info *p)
{
	char **str;

	if ((p->visited & WE_FLAG) || (p->visited & MAP_FLAG))
	{
		error("WE: The identify is crazy", p);
		free(line);
		return ;
	}
	p->visited |= WE_FLAG;
	str = ft_split(line, ' ');
	if (ft_strncmp(str[0], "WE", ft_strlen(str[0])) != 0)
		error("WE: Invalid identify", p);
	if (str[1] == NULL || str[2] != NULL)
		error("WE: Crazy number of elements", p);
	if (str[1] != NULL && open(str[1], O_RDONLY) < 0)
		error("WE: Irregular pass", p);
	if (check_file_name(p, str[1], ".xpm"))
		p->tex_path[2] = ft_strdup(str[1]);
	else
		p->visited &= ~WE_FLAG;
	dp_free(str);
	free(line);
}

void	check_identify_ea(char *line, t_info *p)
{
	char **str;

	if ((p->visited & EA_FLAG) || (p->visited & MAP_FLAG))
	{
		error("EA: The identify is crazy", p);
		free(line);
		return ;
	}
	p->visited |= EA_FLAG;
	str = ft_split(line, ' ');
	if (ft_strncmp(str[0], "EA", ft_strlen(str[0])) != 0)
		error("EA: Invalid identify", p);
	if (str[1] == NULL || str[2] != NULL)
		error("EA: Crazy number of elements", p);
	if (str[1] != NULL && open(str[1], O_RDONLY) < 0)
		error("EA: Irregular pass", p);
	if (check_file_name(p, str[1], ".xpm"))
		p->tex_path[3] = ft_strdup(str[1]);
	else
		p->visited &= ~EA_FLAG;
	dp_free(str);
	free(line);
}

void	check_identify_s(char *line, t_info *p)
{
	char **str;

	if ((p->visited & S_FLAG) || (p->visited & MAP_FLAG))
	{
		error("S: The identify is crazy", p);
		free(line);
		return ;
	}
	p->visited |= S_FLAG;
	str = ft_split(line, ' ');
	if (ft_strncmp(str[0], "S", ft_strlen(str[0])) != 0)
		error("S: Invalid identify", p);
	if (str[1] == NULL || str[2] != NULL)
		error("S: Crazy number of elements", p);
	if (str[1] != NULL && open(str[1], O_RDONLY) < 0)
		error("S: Irregular pass", p);
	if (check_file_name(p, str[1], ".xpm"))
		p->tex_path[4] = ft_strdup(str[1]);
	else
		p->visited &= ~S_FLAG;
	dp_free(str);
	free(line);
}

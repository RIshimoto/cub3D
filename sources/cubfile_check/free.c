/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <rishimot@student.42.tokyo>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:36:11 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 17:40:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	dp_free(char **dp)
{
	int i;

	i = -1;
	while (dp[++i] != NULL)
		free(dp[i]);
	free(dp);
}

void	tab_free(char **dp, int n)
{
	int i;

	i = -1;
	while (++i < n)
		free(dp[i]);
	free(dp);
}

void	all_free(t_info *p)
{
	if (p->visited & NO_FLAG)
		free(p->tex_path[0]);
	if (p->visited & SO_FLAG)
		free(p->tex_path[1]);
	if (p->visited & WE_FLAG)
		free(p->tex_path[2]);
	if (p->visited & EA_FLAG)
		free(p->tex_path[3]);
	if (p->visited & S_FLAG)
		free(p->tex_path[4]);
	tab_free(p->map, p->map_height);
	free(p->tex_path);
	free(p->sprite);
}

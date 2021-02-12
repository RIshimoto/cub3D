/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:57:30 by rishimot          #+#    #+#             */
/*   Updated: 2021/01/03 05:22:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *nptr)
{
	long int	num;
	int			minus;

	while ((*nptr == ' ') || (*nptr == '\t') || (*nptr == '\n') ||\
			(*nptr == '\v') || (*nptr == '\r') || (*nptr == '\f'))
		nptr++;
	minus = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			minus = -1;
		nptr++;
	}
	num = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		if (num > (INT_MAX - (*nptr - '0')) / 10)
			return (-1);
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * minus);
}

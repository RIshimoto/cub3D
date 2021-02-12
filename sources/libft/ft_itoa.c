/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:03:11 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/14 19:53:40 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		keta(long int n)
{
	int	k;

	if (n == 0)
		return (1);
	k = 0;
	if (n < 0)
	{
		n *= -1;
		k++;
	}
	while (n)
	{
		k++;
		n /= 10;
	}
	return (k);
}

char			*ft_itoa(int n)
{
	long int	num;
	int			len;
	int			i;
	char		*p;

	num = n;
	len = keta(n);
	i = 0;
	if (!(p = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	if (num == 0)
		p[0] = '0';
	else if (num < 0)
	{
		num *= -1;
		p[0] = '-';
	}
	while (num)
	{
		p[len - i - 1] = '0' + (num % 10);
		num /= 10;
		i++;
	}
	p[len] = '\0';
	return (p);
}

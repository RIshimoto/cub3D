/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 00:16:06 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/13 03:21:40 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	keta(long int n)
{
	int	k;

	k = 0;
	while (n)
	{
		k++;
		n /= 10;
	}
	return (k);
}

void		ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	long int	k;
	size_t		len;
	size_t		i;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb == 0)
		ft_putchar_fd('0', fd);
	len = keta(nb);
	k = 1;
	i = 1;
	while (i++ < len)
		k *= 10;
	i = 0;
	while (i++ < len)
	{
		ft_putchar_fd('0' + (nb / k), fd);
		nb %= k;
		k /= 10;
	}
}

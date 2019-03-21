/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:27:04 by atourner          #+#    #+#             */
/*   Updated: 2017/11/12 19:20:49 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int		ft_power(int n)
{
	if (n == -1)
		return (1);
	if (n == 0)
		return (1);
	return (10 * ft_power(n - 1));
}

void			ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		tmp;

	len = 0;
	tmp = n;
	if (n < 0)
		write(fd, "-", 1);
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	len = ft_power(len - 1);
	while (len > 0)
	{
		tmp = ((n - n % len) / len);
		tmp = ((tmp < 0) ? (-tmp) + '0' : tmp + '0');
		write(fd, &tmp, 1);
		n %= len;
		len /= 10;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:02:06 by atourner          #+#    #+#             */
/*   Updated: 2018/01/14 10:44:57 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

static long		ft_pow(long n)
{
	if (n == -1)
		return (1);
	if (n == 0)
		return (1);
	return (10 * ft_pow(n - 1));
}

char			*ft_putnbr(int n)
{
	long	len;
	long	tmp;
	char	*str;
	int		i;

	i = -1;
	len = -1;
	tmp = (long)n;
	if (!(str = ft_strnew(15)))
		return (NULL);
	if (n < 0)
		str[++i] = '-';
	while (++len >= 0 && n)
		n /= 10;
	len = ft_pow(len - 1);
	while (len > 0)
	{
		n = (int)(tmp / len);
		n = n < 0 ? -n : n;
		str[++i] = n + '0';
		tmp %= len;
		len /= 10;
	}
	return (str);
}

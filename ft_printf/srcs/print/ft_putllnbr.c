/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 02:14:59 by atourner          #+#    #+#             */
/*   Updated: 2018/01/13 10:49:54 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_putullnbr(uintmax_t n)
{
	int			i;
	char		*str;
	char		*ret;

	i = -1;
	if (!(str = ft_strnew(30)))
		return (NULL);
	if (!n)
		str[0] = '0';
	while (n)
	{
		str[++i] = (n % 10) + '0';
		n /= 10;
	}
	if (!(ret = ft_strr(str)))
		return (NULL);
	return (ret);
}

char		*ft_putllnbr(intmax_t n)
{
	int			i;
	int			neg;
	char		*str;
	char		*ret;

	i = -1;
	neg = 0;
	if (n < 0)
		neg = 1;
	if (!(str = ft_strnew(30)))
		return (NULL);
	if (!n)
		str[0] = '0';
	while (n)
	{
		str[++i] = (n < 0 ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	if (neg)
		str[++i] = '-';
	if (!(ret = ft_strr(str)))
		return (NULL);
	return (ret);
}

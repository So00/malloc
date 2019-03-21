/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo_base_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:25:09 by atourner          #+#    #+#             */
/*   Updated: 2018/01/18 14:25:06 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_itoa_base(uintmax_t nb, uintmax_t wrt, char *base)
{
	uintmax_t	tryes;
	char		*str;
	char		*ret;
	int			j;

	j = -1;
	if (!(str = ft_strnew(40)))
		return (NULL);
	if (nb == 0)
		str[++j] = base[0];
	while (nb != 0)
	{
		tryes = nb % wrt;
		str[++j] = base[tryes];
		nb /= wrt;
	}
	if (!(ret = ft_strr(str)))
		return (NULL);
	return (ret);
}

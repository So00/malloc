/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:16:03 by atourner          #+#    #+#             */
/*   Updated: 2018/01/18 16:20:57 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkwchar(wchar_t c)
{
	int		nb_bit;

	nb_bit = active_bit_check(c);
	if ((MB_CUR_MAX == 1 && nb_bit > 7) || (MB_CUR_MAX == 2 && nb_bit > 11)
			|| (MB_CUR_MAX == 3 && nb_bit > 16) ||
			((int)c >= 0xd800 && (int)c <= 0xdfff) || (int)c > 0x10FFFF
			|| (int)c < 0)
		return (0);
	return (1);
}

int		ft_checkwstr(wchar_t *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_checkwchar(str[i]))
			return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:51:51 by atourner          #+#    #+#             */
/*   Updated: 2018/01/18 18:23:18 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int				active_bit_check(wchar_t c)
{
	int		i;

	i = 0;
	while ((c >> i) != 0)
		i++;
	return (i);
}

char			*ft_put_two_bytes(wchar_t c, char *tab)
{
	char	mask;
	char	mask2;

	mask2 = 0x3F;
	mask = 0xC0;
	tab[0] = (c >> 6) | mask;
	mask = 0x80;
	tab[1] = (c & mask2) | mask;
	return (tab);
}

char			*ft_put_three_bytes(wchar_t c, char *tab)
{
	char	mask;
	char	mask2;

	mask2 = 0x3F;
	mask = 0xE0;
	tab[0] = (c >> 12) | mask;
	mask = 0x80;
	tab[1] = ((c >> 6) & mask2) | mask;
	tab[2] = (c & mask2) | mask;
	return (tab);
}

char			*ft_put_four_bytes(wchar_t c, char *tab)
{
	char	mask;
	char	mask2;

	mask2 = 0x3F;
	mask = 0xF0;
	tab[0] = (c >> 18) | mask;
	mask = 0x80;
	tab[1] = ((c >> 12) & mask2) | mask;
	tab[2] = ((c >> 6) & mask2) | mask;
	tab[3] = (c & mask2) | mask;
	return (tab);
}

char			*ft_putwchar(wchar_t c)
{
	char			*tab;
	int				bit_nb;

	if ((bit_nb = active_bit_check(c)) <= 7
			|| ((int)c < 255 && MB_CUR_MAX == 1))
		return (ft_chardup((char)c));
	if (!ft_checkwchar(c) || !(tab = ft_strnew(3)))
		return (NULL);
	else if (bit_nb <= 11)
		return (ft_put_two_bytes(c, tab));
	else if (bit_nb <= 16)
		return (ft_put_three_bytes(c, tab));
	return (ft_put_four_bytes(c, tab));
}

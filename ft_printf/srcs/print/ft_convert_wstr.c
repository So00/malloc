/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_wstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:32:26 by atourner          #+#    #+#             */
/*   Updated: 2018/01/18 18:20:37 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int		ft_sizeof_wchar(wchar_t c)
{
	int		bit_act;

	if ((bit_act = active_bit_check(c)) == 7)
		return (1);
	if (bit_act <= 11)
		return (2);
	if (bit_act <= 16)
		return (3);
	return (4);
}

char	*ft_convert_wstr(wchar_t *str, int *flags)
{
	int		i;
	char	*ret;
	char	*old;
	char	*to_free;

	i = -1;
	if (!str || (int)str[0] < 0 || !(ret = ft_strnew(1)))
		return (NULL);
	if (str)
		while (ret && str[++i] && (flags['.'] ? flags['.'] >=
					(int)ft_strlen(ret) + ft_sizeof_wchar(str[i]) : 1))
		{
			old = ret;
			if ((to_free = ft_putwchar(str[i])))
			{
				ret = ft_strjoin(ret, to_free);
				free(to_free);
			}
			else
				ret = to_free;
			free(old);
		}
	free(str);
	return (ret);
}

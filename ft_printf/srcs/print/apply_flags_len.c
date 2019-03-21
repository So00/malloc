/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:52:32 by atourner          #+#    #+#             */
/*   Updated: 2018/01/18 18:32:18 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern const char		g_flags[12];

void		put_str_char(char *str, int len, char to_put)
{
	int		i;

	i = -1;
	while (++i < len)
		str[i] = to_put;
}

int			ft_sort_len(char **str, const char c)
{
	if ((c != 'c' && c != 'C') || (c == 'C' &&
				(int)str[ft_get_start(*str)] >= 255))
		return ((int)ft_strlen(*str));
	return (*str == '\0' ? 0 : 1);
}

int			ft_flag_len(char **str, int *flags, const char c)
{
	char		*ret;

	if (!(ret = ft_strnew(flags['1'])))
		return (-1);
	if (flags['-'])
	{
		ft_strcpy(ret, *str);
		put_str_char(&ret[(int)ft_strlen(ret)],
				flags['1'] - (int)ft_strlen(ret), ' ');
	}
	else
	{
		put_str_char(ret, flags['1'] - (int)ft_sort_len(str, c), (flags['0'] ?
					'0' : ' '));
		ft_strcpy(&ret[(int)ft_strlen(ret)], *str);
	}
	free(*str);
	*str = ret;
	if ((ret = ft_strchr(*str, '-')) && (*str)[0] == '0')
	{
		(*str)[0] = '-';
		*ret = '0';
	}
	return ((int)ft_strlen(*str));
}

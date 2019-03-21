/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:17:12 by atourner          #+#    #+#             */
/*   Updated: 2018/01/17 18:15:24 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern const char		g_type[12];

static int		flags_pre_str(char **str, int *flags, char c)
{
	char		*new;
	size_t		size;

	if (c == 'c' || c == 'C' || flags['.'] >= (int)ft_strlen(*str))
		return ((int)ft_strlen(*str));
	size = ((flags['.'] < 0) ? 0 : flags['.']);
	if (!(new = ft_strnew(size)))
		return (-1);
	ft_strncpy(new, *str, size);
	free(*str);
	*str = new;
	return ((int)ft_strlen(*str));
}

static int		str_not_zero(char **str, int *flags, char c)
{
	char		*ret;
	int			i;

	if (flags['.'] == -1 || flags['.'] < (int)ft_strlen(*str))
		return ((int)ft_strlen(*str));
	if (c == '%')
		return (1);
	if (!(ret = ft_strnew(flags['.'] + 2)))
		return (-1);
	i = 0;
	if (str[0][0] == '-')
	{
		i = 1;
		ret[0] = '-';
	}
	put_str_char(&ret[i], flags['.'] - (int)ft_strlen(*str) + i, '0');
	ft_strcpy(&ret[(int)ft_strlen(ret)], &(*str)[i]);
	flags['0'] = 0;
	free(*str);
	*str = ret;
	return ((int)ft_strlen(*str));
}

static int		flags_pre_other(char **str, int *flags, char c)
{
	char	*ret;

	if (str[0][0] != '0')
		return (str_not_zero(str, flags, c));
	else if (flags['.'] == -1)
	{
		free(*str);
		*str = ft_strdup("\0");
		return (0);
	}
	else
	{
		if (!(ret = ft_strnew(flags['.'] + 2)))
			return (-1);
		put_str_char(ret, flags['.'], '0');
		free(*str);
		*str = ret;
	}
	return ((int)ft_strlen(*str));
}

int				ft_flags_pre(char **str, int *flags, char c)
{
	const char	*chr;

	chr = (const char*)ft_strchr(g_type, c);
	if (chr - g_type <= 3)
		return (flags_pre_str(str, flags, c));
	if (c != '%' && flags['0'])
		flags['0'] = 0;
	return (flags_pre_other(str, flags, c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 01:19:41 by atourner          #+#    #+#             */
/*   Updated: 2018/01/18 12:00:05 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern const char g_type[16];

static int	search_format(const char **s)
{
	int		i;
	int		ret;
	int		j;

	ret = -1;
	i = -1;
	while ((*s)[++i] && ret < 0)
	{
		j = -1;
		while (g_type[++j])
			if (g_type[j] == (*s)[i])
				return (j);
	}
	return (0);
}

static void	fill_flag_len(int len, int *flags)
{
	if (len < 0)
		flags['-'] = 1;
	if ((len = (len > 0 ? len : -len)) <= 0)
		len = -1;
	flags['1'] = len;
	flags['*'] = len;
}

void		ft_special_flags(const char **s, int *flags, va_list ap)
{
	int		len;

	if (**s == 'h')
	{
		if ((*s)[1] == 'h')
			flags['H'] = 1;
		else if (!flags['H'])
			flags['h'] = 1;
	}
	else if (**s == 'l')
	{
		if ((*s)[1] == 'l')
			flags['L'] = 1;
		else if (!flags['L'])
			flags['l'] = 1;
	}
	else
	{
		len = va_arg(ap, int);
		fill_flag_len(len, flags);
	}
}

int			ft_flag_star(va_list ap, const char **s, int *flags)
{
	int		len;

	++*s;
	len = va_arg(ap, int);
	if (len < 0)
	{
		if (search_format(s) <= 3)
			flags['-'] = 1;
		else
			return (0);
	}
	len = (len > 0 ? len : -len);
	if (!len)
		len = -1;
	return (len);
}

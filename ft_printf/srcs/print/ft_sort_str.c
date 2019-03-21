/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:44:56 by atourner          #+#    #+#             */
/*   Updated: 2018/01/17 18:41:36 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_sort_str(const char c, va_list ap, int *flags)
{
	wchar_t	*wstr;

	if (c == 's' && !flags['l'])
	{
		wstr = (wchar_t*)va_arg(ap, char*);
		if (!wstr)
			return (ft_convert_flags(c, ft_strdup("(null)"), flags));
		return (ft_convert_flags(c, ft_strdup((char*)wstr), flags));
	}
	else if (c == 'c' && !flags['l'])
		return (ft_convert_flags(c, ft_chardup(va_arg(ap, int)), flags));
	else if (c == 'C' || (c == 'c' && flags['l']))
		return (ft_convert_flags('C',
				ft_convert_wstr(ft_wchardup(va_arg(ap, int)), flags), flags));
		wstr = va_arg(ap, wchar_t*);
	if (!wstr)
		return (ft_convert_flags('S', ft_strdup("(null)"), flags));
	return (ft_convert_flags('S', (char*)ft_convert_wstr(ft_strwdup(wstr),
					flags), flags));
	return (-1);
}

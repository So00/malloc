/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 06:47:01 by atourner          #+#    #+#             */
/*   Updated: 2018/01/18 14:20:49 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern const char	g_flags[12];

static int	superior_flag(int act, int *flags)
{
	int		i;

	i = act;
	while (g_flags[++i])
		if (flags[(int)g_flags[i]])
			return (0);
	return (1);
}

void		get_int(t_type *get, va_list ap, int *flags)
{
	ft_bzero((void*)get, sizeof(t_type));
	if (flags['H'] && superior_flag(6, flags))
		get->val.ll = (long long)((signed char)va_arg(ap, int));
	else if (flags['h'] && superior_flag(7, flags))
		get->val.ll = (long long)((short int)va_arg(ap, int));
	else if (flags['L'] && superior_flag(8, flags))
		get->val.ll = va_arg(ap, long long);
	else if (flags['l'] && superior_flag(8, flags))
		get->val.ll = (long long)va_arg(ap, long);
	else if (flags['j'])
		get->val.im = va_arg(ap, intmax_t);
	else
		get->val.ll = (long long)va_arg(ap, int);
}

void		get_unsigned(t_type *get, va_list ap, int *flags)
{
	ft_bzero((void*)get, sizeof(t_type));
	if (flags['H'] && superior_flag(6, flags))
		get->val.ull = (unsigned long long)
			((unsigned char)va_arg(ap, unsigned int));
	else if (flags['h'] && superior_flag(7, flags))
		get->val.ull = (unsigned long long)
			((unsigned short int)va_arg(ap, unsigned int));
	else if (flags['L'] && superior_flag(8, flags))
		get->val.ull = va_arg(ap, unsigned long long);
	else if (flags['l'] && superior_flag(8, flags))
		get->val.ull = (unsigned long long)va_arg(ap, unsigned long);
	else if (flags['j'])
		get->val.uim = va_arg(ap, uintmax_t);
	else if (flags['z'])
		get->val.ull = (unsigned long long)va_arg(ap, size_t);
	else
		get->val.ull = (unsigned long long)va_arg(ap, unsigned int);
}

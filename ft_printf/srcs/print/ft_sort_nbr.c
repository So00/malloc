/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:38:20 by atourner          #+#    #+#             */
/*   Updated: 2018/01/12 16:55:44 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_sort_nb(const char c, int *flags, t_type *get)
{
	char		*str;

	if (c == 'd' || c == 'i')
		str = ft_putllnbr((intmax_t)get->val.ll);
	if (c == 'p')
		str = ft_itoa_base(get->val.uim, 16, "0123456789abcdef");
	if (c == 'x')
		str = ft_itoa_base(get->val.uim, 16, "0123456789abcdef");
	if (c == 'X')
		str = ft_itoa_base(get->val.uim, 16, "0123456789ABCDEF");
	if (c == 'D')
		str = ft_putllnbr(get->val.im);
	if (c == 'O')
		str = ft_itoa_base(get->val.uim, 8, "012345678");
	if (c == 'o')
		str = ft_itoa_base(get->val.uim, 8, "012345678");
	if (c == 'u')
		str = ft_putullnbr(get->val.uim);
	if (c == 'U')
		str = ft_putullnbr(get->val.uim);
	return (ft_convert_flags(c, str, flags));
}

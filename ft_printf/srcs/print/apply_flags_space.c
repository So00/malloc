/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:26:07 by atourner          #+#    #+#             */
/*   Updated: 2018/01/18 13:47:23 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_space(char **str)
{
	char		*ret;

	if (str[0][0] == '+' || str[0][0] == '-' || str[0][0] == ' ')
		return ((int)ft_strlen(*str));
	if (str[0][0] == '0' && str[0][1] != '\0')
	{
		str[0][0] = ' ';
		return ((int)ft_strlen(*str));
	}
	if (!(ret = ft_strnew((int)ft_strlen(*str) + 1)))
		return (-1);
	ret[0] = ' ';
	ft_strcpy(&ret[1], *str);
	free(*str);
	*str = ret;
	return ((int)ft_strlen(*str));
}

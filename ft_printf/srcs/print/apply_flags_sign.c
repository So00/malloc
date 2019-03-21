/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_sign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:26:41 by atourner          #+#    #+#             */
/*   Updated: 2018/01/13 19:28:46 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flag_sign(char **str, int *flags)
{
	char		*ret;
	int			i;

	i = 0;
	while ((*str)[i] == ' ')
		i++;
	if ((*str)[i] == '-')
		return ((int)ft_strlen(*str));
	else if (i)
		(*str)[i - 1] = '+';
	else if ((*str)[i] == '0' && (*str)[i + 1] != '\0' && flags['0'])
		(*str)[i] = '+';
	else if (!(ret = ft_strnew((int)ft_strlen(*str) + 1)))
		return (-1);
	else
	{
		ret[0] = '+';
		if (ft_strrchr(*str, ' '))
			*(ft_strrchr(*str, ' ')) = '\0';
		ft_strcpy(&ret[1], *str);
		free(*str);
		*str = ret;
	}
	return ((int)ft_strlen(*str));
}

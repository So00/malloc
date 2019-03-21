/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 22:31:41 by atourner          #+#    #+#             */
/*   Updated: 2018/03/08 10:35:35 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_free_ar(void **mem)
{
	char	**str;
	int		i;

	if (mem)
	{
		i = -1;
		str = (char**)mem;
		while (str[++i])
			ft_strdel(&str[i]);
		free(str);
		str = NULL;
	}
}

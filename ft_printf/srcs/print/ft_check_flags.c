/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 17:09:21 by atourner          #+#    #+#             */
/*   Updated: 2018/01/17 17:33:57 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern const char		g_flags[12];
extern const char		g_type[16];

int		ft_check_flags(const char c)
{
	int		i;

	i = -1;
	if (ft_isdigit(c))
		return (1);
	while (g_flags[++i])
		if (g_flags[i] == c)
			return (1);
	i = -1;
	while (g_type[++i])
		if (g_type[i] == c)
			return (1);
	return (0);
}

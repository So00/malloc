/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 21:48:42 by atourner          #+#    #+#             */
/*   Updated: 2018/01/13 10:50:33 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strr(char *str)
{
	size_t		i;
	size_t		j;
	char		*new;

	i = ft_strlen(str);
	j = -1;
	if (!(new = ft_strnew(i)))
		return (NULL);
	while (--i)
		new[++j] = str[i];
	new[j + 1] = str[i];
	free(str);
	return (new);
}

wchar_t		*ft_strwr(wchar_t *str)
{
	size_t		i;
	size_t		j;
	wchar_t		*new;

	i = ft_strwlen(str);
	j = -1;
	if (!(new = ft_strwnew(i)))
		return (NULL);
	while (--i)
		new[++j] = str[i];
	new[j + 1] = str[i];
	free(str);
	return (new);
}

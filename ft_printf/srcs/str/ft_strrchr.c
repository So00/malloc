/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:56:07 by atourner          #+#    #+#             */
/*   Updated: 2018/01/14 19:23:27 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	while (i != -1)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i--;
	}
	return (NULL);
}

wchar_t	*ft_strrwchr(wchar_t *s, wchar_t c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	while (i != -1)
	{
		if (s[i] == c)
			return ((wchar_t*)&s[i]);
		i--;
	}
	return (NULL);
}

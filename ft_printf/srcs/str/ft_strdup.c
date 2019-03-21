/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:11:53 by atourner          #+#    #+#             */
/*   Updated: 2018/01/18 16:42:05 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char			*ft_strdup(char *src)
{
	char	*cpy;
	int		act;

	act = 0;
	if (!src)
		return (NULL);
	if ((cpy = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		while (src[act])
		{
			cpy[act] = src[act];
			act++;
		}
	if (cpy)
		cpy[act] = '\0';
	return (cpy);
}

char			*ft_strndup(char *src, int n)
{
	char		*cpy;
	int			act;

	act = -1;
	if (!src)
		return (NULL);
	if ((cpy = ft_strnew(ft_strlen(src) + 1)))
	{
		while (src[++act] && act < n)
			cpy[act] = src[act];
		cpy[act] = '\0';
	}
	return (cpy);
}

wchar_t			*ft_strwdup(wchar_t *src)
{
	wchar_t		*cpy;
	int			act;

	act = 0;
	if (!src)
		return (NULL);
	if ((cpy = ft_strwnew(ft_strwlen(src) + 1)))
		while (src[act])
		{
			cpy[act] = src[act];
			act++;
		}
	if (cpy)
		cpy[act] = '\0';
	return (cpy);
}

wchar_t			*ft_wchardup(wchar_t src)
{
	wchar_t		*cpy;

	if ((cpy = ft_strwnew(1)))
		cpy[0] = src;
	return (cpy);
}

char			*ft_chardup(char c)
{
	char	*new;

	if (!(new = ft_strnew(1)))
		return (NULL);
	new[0] = c;
	return (new);
}

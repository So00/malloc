/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:35:06 by atourner          #+#    #+#             */
/*   Updated: 2017/12/15 00:46:20 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

wchar_t	*ft_strwncpy(wchar_t *dst, wchar_t *src, int len)
{
	int		i;

	i = -1;
	if (len == -1)
		len = 0;
	if (src)
	{
		while (++i < len && src[i])
			dst[i] = src[i];
		i--;
	}
	while (++i < len)
		dst[i] = ' ';
	dst[i] = '\0';
	return (dst);
}

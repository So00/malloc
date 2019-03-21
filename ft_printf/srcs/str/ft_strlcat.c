/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:56:42 by atourner          #+#    #+#             */
/*   Updated: 2017/11/12 19:32:54 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strleng(const char *src)
{
	size_t		len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	slen;

	len = 0;
	slen = ft_strleng(src);
	while (*dst && size > 0)
	{
		dst++;
		len++;
		size--;
	}
	while (*src && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		*dst = '\0';
		size--;
	}
	return (slen + len);
}

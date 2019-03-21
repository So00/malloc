/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:16:47 by atourner          #+#    #+#             */
/*   Updated: 2017/11/12 15:23:06 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char		*str;

	str = (unsigned char*)s;
	while (n--)
	{
		if (*str != (unsigned char)c)
			str++;
		else
			return ((void*)str);
	}
	return (NULL);
}

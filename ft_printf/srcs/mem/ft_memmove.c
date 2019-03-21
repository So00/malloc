/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:20:29 by atourner          #+#    #+#             */
/*   Updated: 2017/11/11 18:27:50 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void		ft_iterate(char *s1, char *s3, size_t i)
{
	s1 = s1 + i;
	s3 = s3 + i;
}

void			*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*s1;
	char		s2[4096];
	char		*s3;
	size_t		i;

	s1 = (char*)src;
	s3 = (char*)dst;
	i = 0;
	while (n -= i)
	{
		i = 0;
		while (i < 4095 && i < n)
		{
			s2[i] = s1[i];
			i++;
		}
		i = 0;
		while (i < 4095 && i < n)
		{
			s3[i] = s2[i];
			i++;
		}
		ft_iterate(s1, s3, i);
	}
	return ((void*)dst);
}

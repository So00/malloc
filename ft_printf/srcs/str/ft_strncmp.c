/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:17:29 by atourner          #+#    #+#             */
/*   Updated: 2017/11/12 18:44:42 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (n == 0)
		return (0);
	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (0);
		return (1);
	}
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while ((*str1 || *str2) && *str1 == *str2 && i < n - 1)
	{
		str1++;
		str2++;
		i++;
	}
	return (*str1 - *str2);
}

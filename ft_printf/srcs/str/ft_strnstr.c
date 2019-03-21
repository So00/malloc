/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:35:49 by atourner          #+#    #+#             */
/*   Updated: 2017/11/10 12:48:46 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (i + j <= len && (!needle[j] || haystack[i + j] == needle[j]))
		{
			if (!needle[j])
				return ((char*)&haystack[i]);
			j++;
		}
		i++;
	}
	if (haystack[i] == '\0' && haystack[i] == needle[j])
		return ((char*)&haystack[i]);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:03:20 by atourner          #+#    #+#             */
/*   Updated: 2017/11/10 11:37:29 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (haystack[i])
	{
		j = 0;
		while (!needle[j] || haystack[i + j] == needle[j])
		{
			if (!needle[j])
				return ((char*)&haystack[i]);
			j++;
		}
		i++;
	}
	if (haystack[i] == needle[j])
		return ((char*)&haystack[i]);
	return (NULL);
}

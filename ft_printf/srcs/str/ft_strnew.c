/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:54:08 by atourner          #+#    #+#             */
/*   Updated: 2018/01/14 15:49:45 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	if ((new = (char*)malloc(sizeof(char) * size + 1)))
	{
		i = 0;
		while (i < size)
		{
			new[i] = '\0';
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}

wchar_t		*ft_strwnew(size_t size)
{
	wchar_t		*new;
	size_t		i;

	if ((new = (wchar_t*)malloc(sizeof(wchar_t) * size + 1)))
	{
		i = 0;
		while (i < size)
		{
			new[i] = '\0';
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:11:58 by atourner          #+#    #+#             */
/*   Updated: 2017/11/11 16:16:02 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	act;

	if (s)
		if ((new = (char*)malloc(sizeof(char) * len + 1)))
		{
			act = 0;
			new[len] = '\0';
			while (len != 0)
			{
				new[act] = s[start + act];
				len--;
				act++;
			}
			return (new);
		}
	return (NULL);
}

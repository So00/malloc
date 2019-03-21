/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:07:19 by atourner          #+#    #+#             */
/*   Updated: 2017/11/10 19:17:35 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strleng(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i + 1);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (s)
		if ((new = (char*)malloc(sizeof(char) * ft_strleng(s))))
		{
			while (s[i])
			{
				new[i] = (*f)(i, s[i]);
				i++;
			}
			new[i] = '\0';
			return (new);
		}
	return (NULL);
}

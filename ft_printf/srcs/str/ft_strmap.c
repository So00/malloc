/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:19:37 by atourner          #+#    #+#             */
/*   Updated: 2017/11/13 12:12:56 by atourner         ###   ########.fr       */
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

char			*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = 0;
	if (s)
		if ((new = (char*)malloc(sizeof(char) * ft_strleng(s))))
		{
			while (s[i])
			{
				new[i] = (*f)(s[i]);
				i++;
			}
			new[i] = '\0';
			return (new);
		}
	return (NULL);
}

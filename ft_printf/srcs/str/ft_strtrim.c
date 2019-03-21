/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:29:11 by atourner          #+#    #+#             */
/*   Updated: 2017/11/11 18:44:12 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_begin(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	if (s[i] != '\0')
		return (i);
	return (0);
}

static int		ft_strleng(char const *s)
{
	int		i;
	int		j;

	i = ft_begin(s);
	j = 0;
	while (s[j])
		j++;
	while ((s[j] == '\n' || s[j] == '\t' || s[j] == ' ' || !s[j]) && i != j)
		j--;
	return (j - i + 2);
}

static int		ft_test_white(char const *s, int start)
{
	if (s[start] == '\n' || s[start] == ' ' || s[start] == '\t')
		while (1)
		{
			if (!s[start])
				return (0);
			if (s[start] != '\n' && s[start] != ' ' && s[start] != '\t')
				return (1);
			start++;
		}
	return (1);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	if (s)
		if ((new = (char*)malloc(sizeof(char) * (ft_strleng(s)))))
		{
			i = ft_begin(s);
			while (s[i] && ft_test_white(s, i))
			{
				new[j] = s[i];
				j++;
				i++;
			}
			new[j] = '\0';
			return (new);
		}
	return (NULL);
}

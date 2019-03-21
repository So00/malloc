/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:30:36 by atourner          #+#    #+#             */
/*   Updated: 2018/01/20 17:53:34 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int		ft_count_word(char const *s, char c)
{
	int		word_nb;
	int		i;

	word_nb = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_nb++;
			while (s[i + 1] != c && s[i + 1])
				i++;
		}
		i++;
	}
	return (word_nb);
}

static char		*ft_sub(char const *s, int start, int c)
{
	int		len;
	char	*new;
	int		i;

	i = 0;
	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	if (!(new = ft_strnew(len)))
		return (NULL);
	new[len] = '\0';
	while (i != len)
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}

static int		ft_start(char const *s, char c, int start, int i)
{
	if (start == 0 && s[start] != c && i == 0)
		return (0);
	if (s[start] != c)
		while (s[start] != c && s[start])
			start++;
	while (s[start] == c && s[start])
		start++;
	return (start);
}

char			**ft_strsplit(char const *s, char c)
{
	int		word_nb;
	char	**split_tab;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	word_nb = ft_count_word(s, c);
	i = 0;
	start = 0;
	if ((split_tab = (char**)malloc(sizeof(char*) * (word_nb + 1))))
		while (i <= word_nb)
		{
			start = ft_start(s, c, start, i);
			if (i != word_nb && (split_tab[i] = ft_sub(s, start, c)))
				i++;
			else if (i == word_nb)
			{
				split_tab[i] = NULL;
				i++;
			}
			else
				return (NULL);
		}
	return (split_tab);
}

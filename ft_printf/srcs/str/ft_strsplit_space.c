/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:30:36 by atourner          #+#    #+#             */
/*   Updated: 2018/04/02 19:14:44 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\f')
		return (1);
	return (0);
}

static int		ft_count_word(char const *s)
{
	int		word_nb;
	int		i;

	word_nb = 0;
	i = 0;
	while (s[i])
	{
		if (!is_space(s[i]))
		{
			word_nb++;
			while (!is_space(s[i + 1]) && s[i + 1])
				i++;
		}
		i++;
	}
	return (word_nb);
}

static char		*ft_sub(char const *s, int start)
{
	int		len;
	char	*new;

	len = 0;
	while (s[start + len] && !is_space(s[start + len]))
		len++;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new[len] = '\0';
	len = 0;
	while (s[start + len] && !is_space(s[start + len]))
	{
		new[len] = s[start + len];
		len++;
	}
	return (new);
}

static int		ft_start(char const *s, int start, int i)
{
	if (start == 0 && !is_space(s[start]) && i == 0)
		return (0);
	while (!is_space(s[start]) && s[start])
		start++;
	while (is_space(s[start]) && s[start])
		start++;
	return (start);
}

char			**ft_strsplit_space(char const *s)
{
	int		word_nb;
	char	**split_tab;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	word_nb = ft_count_word(s);
	i = 0;
	start = 0;
	if ((split_tab = (char**)malloc(sizeof(char*) * (word_nb + 1))))
		while (i <= word_nb)
		{
			start = ft_start(s, start, i);
			if (i != word_nb && (split_tab[i] = ft_sub(s, start)))
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

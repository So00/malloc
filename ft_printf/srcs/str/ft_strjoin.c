/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:59:03 by atourner          #+#    #+#             */
/*   Updated: 2018/01/17 18:38:35 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((new = ft_strnew(ft_strlen((char*)s1) + ft_strlen((char*)s2))))
	{
		if (s1)
			while (s1[i])
			{
				new[i] = s1[i];
				i++;
			}
		if (s2)
			while (s2[j])
			{
				new[i + j] = s2[j];
				j++;
			}
		new[i + j] = '\0';
		return (new);
	}
	return (NULL);
}

char			*ft_strnjoin(char *s1, char *s2, int n)
{
	char		*new;
	int			i;
	int			j;

	i = 1;
	if (s1)
		i = (int)ft_strlen(s1);
	if (!(new = ft_strnew(i + n)))
		return (NULL);
	i = -1;
	j = -1;
	while (++i >= 0 && s1 && s1[i])
		new[i] = s1[i];
	while (s2[++j] && j < n)
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (new);
}

wchar_t			*ft_strwjoin(wchar_t *s1, wchar_t *s2)
{
	wchar_t		*new;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (s1)
		i = (int)ft_strwlen(s1);
	j = (int)ft_strwlen(s2);
	if ((new = ft_strwnew(i + j)))
	{
		i = -1;
		j = -1;
		while (++i >= 0 && s1 && s1[i])
			new[i] = s1[i];
		if (s1)
			free(s1);
		while (++j >= 0 && s2 && s2[j])
			new[i + j] = s2[j];
		if (s2)
			free(s2);
		new[i + j] = '\0';
		return (new);
	}
	return (NULL);
}

wchar_t			*ft_strnwjoin(wchar_t *s1, char *s2, int n)
{
	wchar_t		*new;
	int			i;
	int			j;

	i = 1;
	if (s1)
		i = (int)ft_strwlen(s1);
	if (!(new = ft_strwnew(i + n)))
		return (NULL);
	i = -1;
	j = -1;
	while (++i >= 0 && s1 && s1[i])
		new[i] = s1[i];
	while (s2[++j] && j < n)
		new[i + j] = (wchar_t)s2[j];
	new[i + j] = '\0';
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_sharp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:44:47 by atourner          #+#    #+#             */
/*   Updated: 2018/01/18 15:23:45 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern const char		g_flags[12];

int			ft_get_start(char *str)
{
	int i;

	i = -1;
	while (str[++i] == ' ')
		;
	return (i);
}

static int	ft_only_sp_and_zero(char *str)
{
	int		i;

	i = -1;
	while (str[++i] == '0' || str[i] == ' ')
		;
	if (i == (int)ft_strlen(str))
		return (1);
	return (0);
}

int			ft_case_sharp_o(char **str)
{
	char		*ret;
	int			start;

	if ((start = ft_get_start(*str)) && (*str)[start] != '0')
	{
		(*str)[start - 1] = '0';
		return ((int)ft_strlen(*str));
	}
	ret = ft_strrchr(*str, ' ');
	if ((*str)[0] == '0' || (*str)[start] == '0')
		return ((int)ft_strlen(*str));
	if (ret && *(ret + 1) == '\0')
		*ret = '\0';
	if (!(ret = ft_strnew((int)ft_strlen(*str) + 1)))
		return (-1);
	ret[0] = '0';
	ft_strcpy(&ret[1], *str);
	free(*str);
	*str = ret;
	return ((int)ft_strlen(*str));
}

int			ft_case_other_sharp(char **str, char to_put)
{
	char		*ret;

	ret = ft_strrchr(*str, ' ');
	if (ret && (*str)[0] != ' ')
		(*str)[(int)ft_strlen(*str) -
			((ret[1] == '\0' && *(--ret) == ' ') ? 2 : 1)] = '\0';
	if (ft_get_start(*str) >= 2)
	{
		(*str)[ft_get_start(*str) - 1] = to_put;
		(*str)[ft_get_start(*str) - 1] = '0';
		return ((int)ft_strlen(*str));
	}
	if (!(ret = ft_strnew((int)ft_strlen(*str) + 2)))
		return (-1);
	ret[0] = '0';
	ret[1] = to_put;
	if ((*str)[0] == '0')
		ft_strcpy(&ret[2], &((*str)[0]));
	else
		ft_strcpy(&ret[2], *str);
	free(*str);
	*str = ret;
	return ((int)ft_strlen(*str));
}

int			flag_sharp(const char c, char **str, int *flags)
{
	int		len;

	if (ft_only_sp_and_zero(*str) && (c == 'x' || c == 'X'))
		return (len = (int)ft_strlen(*str));
	if ((*str)[0] == '0' && (*str)[1] == '0' &&
			(((c == 'x' || c == 'X') && !flags['.']) ||
				(ft_only_sp_and_zero(*str) && flags['1'] && c == 'p')))
	{
		(*str)[1] = (char)c;
		if (c == 'p')
			(*str)[1] = 'x';
	}
	else
	{
		if (c == 'o' || c == 'O')
			ft_case_sharp_o(str);
		else if (c == 'X')
			ft_case_other_sharp(str, 'X');
		else
			ft_case_other_sharp(str, 'x');
	}
	return ((len = (int)ft_strlen(*str)));
}

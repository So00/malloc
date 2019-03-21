/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:50:29 by atourner          #+#    #+#             */
/*   Updated: 2018/01/18 16:39:07 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern const char		g_flags[12];

static int	ft_start(char *str)
{
	int		i;

	i = -1;
	while (str[++i] && (str[i] == ' ' || str[i] == '0'))
		i++;
	return (i);
}

static int	char_zero(char *str, int *flags, int len)
{
	int		ret;

	ret = 0;
	if (flags['-'])
	{
		ret += ft_putchar('\0');
		ret += ft_putnstr(str, (len > 0) ? len - 1 : 0);
	}
	else
	{
		ret += ft_putnstr(str, (len > 0) ? len : 0);
		ret += ft_putchar('\0');
	}
	return (ret);
}

static int	apply_flags(const char c, char *str, int *flags, int tmp)
{
	int		len;

	len = tmp;
	if (flags['.'] && len != -1)
		len = ft_flags_pre(&str, flags, c);
	if (flags['1'] > (int)ft_strlen(str) && len != -1)
		len = ft_flag_len(&str, flags, c);
	if (flags['#'] && (c == 'o' || c == 'O' || c == 'x'
			|| c == 'X' || c == 'p') && len != -1)
		len = flag_sharp(c, &str, flags);
	if (flags['+'] && (c == 'd' || c == 'i') && len != -1)
		len = flag_sign(&str, flags);
	if (flags[' '] && (c == 'd' || c == 'i' || c == 'D') && len != -1)
		len = flag_space(&str);
	if (len != -1 && (c == 'C' || c == 'c') && str[ft_start(str)] == '\0' &&
			tmp == 0)
		len = char_zero(str, flags, len);
	else if (len != -1)
		len = ft_putstr(str);
	free(str);
	return (len);
}

int			ft_convert_flags(char c, char *str, int *flags)
{
	int		tmp;

	tmp = (int)ft_strlen(str);
	return (apply_flags((const char)c, str, flags, tmp));
}

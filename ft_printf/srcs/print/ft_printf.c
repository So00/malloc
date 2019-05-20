/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:01:40 by atourner          #+#    #+#             */
/*   Updated: 2018/01/21 01:40:04 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char		g_flags[12] = "*.+#0- hljz\0";
const char		g_type[16] = "sScC%dipDoOuUxX\0";

static void	ft_get_flags(const char **s, int *flags, va_list ap)
{
	int		i;

	i = -1;
	while (++i < 11)
		if (**s == g_flags[i])
		{
			if (**s == '.')
			{
				if (s[0][1] >= '0' && s[0][1] <= '9' && !flags['.'])
					flags['.'] = ft_atoi((char*)s[0] + 1);
				if (!flags['.'] && s[0][1] != '*')
					flags['.'] = -1;
				else if (!flags['.'] && s[0][1] == '*')
					flags['.'] = ft_flag_star(ap, s, flags);
			}
			else if (**s == 'h' || **s == 'l' || **s == '*')
				ft_special_flags(s, flags, ap);
			else
				flags[(int)g_flags[i]] = 1;
		}
	if (ft_isdigit(**s) && (!flags['1'] || flags['*']))
		flags['1'] = ft_atoi((char*)*s);
	while (((ft_isdigit(s[0][0]) && (ft_isdigit(s[0][1])))
				|| (**s == '.' && flags['.'] && ft_isdigit(s[0][1]))))
		++*s;
}

static int	ft_compatible_format(char *s, int *flags)
{
	int		i;

	i = -1;
	while (++i < 15)
		if (*s == g_type[i])
		{
			if (g_type[i] == 'p')
			{
				flags['j'] = 1;
				flags['#'] = 1;
			}
			if (*s == 'D' || *s == 'O' || *s == 'U')
			{
				flags['h'] = 0;
				flags['H'] = 0;
				flags['l'] = 1;
			}
			return (i);
		}
	return (i);
}

int			choose_type(const char c, int *flags)
{
	int		i;

	i = 4;
	while (++i < 15)
		if (c == g_type[i] && i <= 6)
		{
			if ((c == 'd' || c == 'i') && flags['z'])
				return (1);
			return (0);
		}
	return (1);
}

int			ft_convert(const char **format, va_list ap,
		void (*f[2])(), t_type *get)
{
	int			flags[128];
	char		act_type;

	ft_bzero(flags, sizeof(int) * 128);
	while (++*format && **format && ft_compatible_format((char*)*format,
				flags) == 15 && ft_check_flags(**format))
		ft_get_flags(format, flags, ap);
	act_type = (char)**format;
	if (**format)
		++*format;
	if (ft_compatible_format(&act_type, flags) <= 3)
		return (ft_sort_str((const char)act_type, ap, flags));
	else if (ft_compatible_format(&act_type, flags) < 15
			&& act_type != '%')
	{
		f[choose_type((const char)act_type, flags)](get, ap, flags);
		return (ft_sort_nb((const char)act_type, flags, get));
	}
	else if (act_type == '%')
		return (ft_convert_flags(act_type, ft_strdup("%\0"), flags));
	if (act_type)
		return (ft_convert_flags('c', ft_chardup(act_type), flags));
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	void	(*get_arg[2])(t_type*, va_list, int*);
	t_type	get;
	int		len;
	char	*arg;

	len = 0;
	arg = (char*)format;
	get_arg[0] = &get_int;
	get_arg[1] = &get_unsigned;
	va_start(ap, format);
	while (arg && len >= 0 && format)
	{
		ft_bzero(&get, sizeof(get));
		arg = ft_strchr(format, '%');
		if (!arg)
			len += ft_putstr(format);
		if (arg > (char*)format)
			len += ft_putnstr((char*)format, arg - (char*)format);
		if (arg && (format = (const char*)arg))
			get.tmp = ft_convert(&format, ap, get_arg, &get);
		len = (get.tmp < 0) ? get.tmp : len + get.tmp;
	}
	va_end(ap);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:10:34 by atourner          #+#    #+#             */
/*   Updated: 2018/01/20 13:35:08 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct				s_type
{
	union
	{
		long long			ll;
		unsigned long long	ull;
		char				c;
		unsigned char		uc;
		char				*str;
		wchar_t				wc;
		wchar_t				*wstr;
		intmax_t			im;
		uintmax_t			uim;
	}						val;
	int						tmp;
}							t_type;

int							ft_printf(const char *format, ...);
char						*ft_itoa_base(uintmax_t nb, uintmax_t wrt,
		char *base);
int							ft_convert_flags(char c, char *str,
		int *flags);
int							ft_sort_nb(const char c, int *flags, t_type *get);
int							ft_sort_str(const char c, va_list ap, int *flags);
void						get_int(t_type *get, va_list ap, int *flags);
void						get_unsigned(t_type *get, va_list ap, int *flags);
int							ft_flags_pre(char **str, int *flags, char c);
int							active_bit_checker(wchar_t c);
char						*ft_len_str(char *dst, int len, char *src);
void						ft_special_flags(const char **s, int *flags,
		va_list ap);
void						put_str_char(char *str, int len,
		char to_put);
int							ft_check_flags(const char c);
int							flag_sharp(const char c, char **str, int *flags);
int							flag_space(char **str);
int							flag_sign(char **str, int *flags);
int							choose_type(const char c, int *flags);
int							ft_get_start(char *str);
int							ft_flag_len(char **str, int *flags, const char c);
wchar_t						*ft_strrwchr(wchar_t *s, wchar_t c);
int							ft_printw_str(char *str);
int							ft_flag_star(va_list ap, const char **s,
		int *flags);

#endif

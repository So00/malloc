/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:20:26 by atourner          #+#    #+#             */
/*   Updated: 2018/06/15 12:24:16 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

long			ft_power(long x, long pow);

size_t			ft_strlen(char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

void			ft_bzero(void *s, size_t n);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char const *s, int fd);
void			ft_putnstr_fd(char const *s, int fd, int nb);
void			ft_strclr(char *s);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			*ft_memchr(void const *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);
void			ft_free_ar(void **str);

char			*ft_strchr(const char *s, int c);
char			*ft_strlower(char *str);
char			*ft_strupper(char *str);
char			*ft_putnbr(int n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(char *src);
char			*ft_itoa(int n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_chardup(char c);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strr(char *str);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
char			*ft_skip_char(char *str, char c);
char			*ft_putwchar(wchar_t c);
char			*ft_convert_wstr(wchar_t *str, int *flags);

char			**ft_strsplit(char const *s, char c);
char			**ft_strsplit_space(char const *s);

int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_putchar(char c);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_iswhitespace(char c);
int				ft_isdigit(int c);
int				ft_isstrdigit(char *str);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strcmp(char const *s1, char const *s2);
int				ft_strncmp(char const *s1, char const *s2, size_t n);
int				ft_checkwchar(wchar_t c);
int				ft_checkwstr(wchar_t *str);
int				active_bit_check(wchar_t c);
int				ft_putnbr_fd(int n, int fd);
int				ft_putstr(char const *s);
int				ft_putnstr(char *str, int n);

char			*ft_putullnbr(uintmax_t n);
char			*ft_putllnbr(intmax_t n);
char			*ft_strnjoin(char *s1, char *s2, int n);
char			*ft_strndup(char *src, int n);
wchar_t			*ft_strwnew(size_t size);
size_t			ft_strwlen(wchar_t *s);
wchar_t			*ft_strwjoin(wchar_t *s1, wchar_t *s2);
wchar_t			*ft_strnwjoin(wchar_t *s1, char *s2, int n);
wchar_t			*ft_strwcpy(wchar_t *dst, wchar_t *src);
wchar_t			*ft_strwr(wchar_t *str);
wchar_t			*ft_strwdup(wchar_t *src);
wchar_t			*ft_wchardup(wchar_t src);
wchar_t			*ft_strwncpy(wchar_t *dst, wchar_t *src, int len);

#endif

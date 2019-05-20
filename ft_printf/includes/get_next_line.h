/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:10:53 by atourner          #+#    #+#             */
/*   Updated: 2018/02/16 18:03:50 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# include "libft.h"

int					get_next_line(const int fd, char **line);

typedef struct		s_sav_str
{
	char	*buff;
	size_t	len;
}					t_sav_str;

#endif

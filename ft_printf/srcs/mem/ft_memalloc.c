/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:52:21 by atourner          #+#    #+#             */
/*   Updated: 2017/11/07 15:24:19 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*new;
	char	*act;
	size_t	i;

	if ((new = malloc(size)))
	{
		act = (char*)new;
		i = 0;
		while (i < size)
		{
			*(act + i) = 0;
			i++;
		}
		return (new);
	}
	return (NULL);
}

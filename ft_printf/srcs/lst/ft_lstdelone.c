/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:19:15 by atourner          #+#    #+#             */
/*   Updated: 2017/12/06 11:33:04 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdlib.h>

void		ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	(*del)((void*)alst[0], alst[0]->content_size);
	alst[0] = NULL;
}

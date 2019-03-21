/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:48:48 by atourner          #+#    #+#             */
/*   Updated: 2017/12/06 11:32:52 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst[0]->next)
		ft_lstdelone(&alst[0]->next, (*del));
	(*del)((void*)alst[0], alst[0]->content_size);
	alst[0] = NULL;
}

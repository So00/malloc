/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:02:44 by atourner          #+#    #+#             */
/*   Updated: 2017/12/06 11:33:26 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdlib.h>

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*act;

	act = lst;
	while (act)
	{
		(*f)(act);
		act = act->next;
	}
}

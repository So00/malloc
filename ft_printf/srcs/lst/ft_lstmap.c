/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 12:07:20 by atourner          #+#    #+#             */
/*   Updated: 2017/12/06 11:33:39 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*act;
	t_list		*act_new;

	if (lst && (new = ft_lstnew(NULL, 0)))
	{
		act = lst;
		act_new = new;
		while (act)
		{
			act_new->next = (*f)(act);
			act_new = act_new->next;
			act = act->next;
		}
		act_new = new->next;
		return (act_new);
	}
	return (NULL);
}

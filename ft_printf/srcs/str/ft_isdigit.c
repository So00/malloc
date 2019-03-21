/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:38:19 by atourner          #+#    #+#             */
/*   Updated: 2018/02/26 16:29:16 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isstrdigit(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit((int)str[i]))
			return (0);
	return (1);
}

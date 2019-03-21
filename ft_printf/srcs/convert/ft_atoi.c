/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:49:38 by atourner          #+#    #+#             */
/*   Updated: 2018/03/07 14:44:42 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_power_act(long nb)
{
	if (nb == 0 || nb == -1)
		return (1);
	return (10 * ft_power_act(nb - 1));
}

static int		ft_final_nbr(const char *str, long sign, long j, long i)
{
	int		nb;

	nb = 0;
	while (j != 0)
	{
		if (sign == 1)
			nb += j * (str[i] - '0');
		else
			nb -= j * (str[i] - '0');
		i++;
		j /= 10;
	}
	return ((int)nb);
}

static int		ft_strlongcmp(const char *str, char *max, long i)
{
	while (i < 18)
	{
		if (str[i] != max[i])
			return (str[i] - max[i]);
		i++;
	}
	return (str[i] - max[i]);
}

static int		ft_test_long(const char *str, long j, long sign, long i)
{
	if (j > 19 && sign == 1)
		return (-1);
	if (j > 19 && sign == -1)
		return (0);
	i = ft_strlongcmp(str, "9223372036854775807", i);
	if (i > 0 && sign == 1)
		return (-1);
	if (i > 0 && sign == -1)
		return (0);
	return (1);
}

int				ft_atoi(const char *str)
{
	long		i;
	long		j;
	long		sign;

	i = 0;
	j = 0;
	sign = 1;
	while (str[i] && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'
			|| (str[i] == '0' && ft_isdigit(str[i + 1]))))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i + j] >= '0' && str[i + j] <= '9')
		j++;
	if (!j)
		return (0);
	if (j >= 19 && ft_test_long(str, j, sign, i) != 1)
		return (ft_test_long(str, j, sign, i));
	return (ft_final_nbr(str, sign, ft_power_act(j - 1), i));
}

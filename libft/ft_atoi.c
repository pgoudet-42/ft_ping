/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:37:50 by pgoudet           #+#    #+#             */
/*   Updated: 2021/05/20 14:58:31 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

void	ft_atoi_bis(int *neg, int *i, char *str)
{
	*neg = 1;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32
		|| str[*i] == ',' || ft_isalpha(str[*i]) == 1)
		*i += 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*neg = -(*neg);
		*i += 1;
	}
}

double	ft_atoi(char *str)
{
	int	res;
	int	neg;
	int	i;

	res = 0;
	neg = 1;
	i = 0;
	ft_atoi_bis(&neg, &i, str);
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		res = res * 10 + str[i] - 48;
		i += 1;
	}
	return (res = res * neg);
}

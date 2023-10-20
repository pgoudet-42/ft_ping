/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:48:58 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/11 12:44:23 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_int(long int l)
{
	int	compt;

	compt = 0;
	if (l < 0 || l == -0)
		compt++;
	while (l != 0)
	{
		l = l / 10;
		compt++;
	}
	return (compt);
}

char	*ft_itoa_bis(char *tab, long int l)
{
	int	i;

	i = ft_strlen_int(l) - 1;
	if (l == -0)
		tab[0] = 48;
	if (l < 0)
		l = -l;
	while (l != 0)
	{
		tab[i] = l % 10 + 48;
		l = l / 10;
		i--;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char		*tab;
	long int	l;

	l = (long int)n;
	if (l < 0)
	{
		tab = malloc(sizeof(char) * (ft_strlen_int(l)) + 1);
		if (!tab)
			return (NULL);
		tab[0] = '-';
	}
	else
		tab = malloc(sizeof(char) * ft_strlen_int(l) + 1);
	if (!tab)
		return (NULL);
	tab[ft_strlen_int(l)] = 0;
	tab = ft_itoa_bis(tab, l);
	return (tab);
}

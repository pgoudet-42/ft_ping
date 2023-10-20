/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:02:38 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/25 17:29:41 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tab)
		return (0);
	while (*s)
	{
		tab[i] = f(i, *s);
		s++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 08:30:54 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/11 12:48:09 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (0);
	if (start >= ft_strlen(s))
	{
		tab[0] = 0;
		return (tab);
	}
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[len] = 0;
	return (tab);
}

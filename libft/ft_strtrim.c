/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:06:12 by pgoudet           #+#    #+#             */
/*   Updated: 2021/04/11 12:47:47 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_set(char const s1, char const *set)
{
	char	c;
	int		j;

	j = 0;
	c = (char)s1;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

int	find_first_pos(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_is_set(s1[i], set) == 1)
		i++;
	return (i);
}

int	find_last_pos(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	i--;
	while (i > 0 && ft_is_set(s1[i], set) == 1)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		pos1;
	int		pos2;

	pos1 = find_first_pos(s1, set);
	pos2 = find_last_pos(s1, set) + 1;
	if (pos1 > pos2)
	{
		tab = ft_calloc(1, 1);
		if (!tab)
			return (NULL);
		return (tab);
	}
	tab = ft_substr(s1, (unsigned int)pos1, (size_t)(pos2 - pos1));
	return (tab);
}

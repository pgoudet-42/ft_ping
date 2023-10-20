/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:13:21 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/24 16:56:22 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *need, size_t len)
{
	size_t	i;
	int		j;
	char	*tab;

	i = 0;
	if (ft_strlen(need) == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] == need[j]) && (j + i) < len)
		{
			if (need[j + 1] == 0)
				return (tab = (char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:02:08 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/28 16:29:32 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*tab;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
		{
			tab = (char *)&s[i];
			return (tab);
		}
		i++;
	}
	if (c == '\0')
		return (tab = (char *)&s[i]);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:57:44 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/25 11:47:36 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	i = -1;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (++i < n)
	{
		if (c1[i] != c2[i])
		{
			return (c1[i] - c2[i]);
		}
	}
	return (0);
}

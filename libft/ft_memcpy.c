/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:58:26 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/25 09:40:27 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*tab;
	const char	*tab2;

	if (dest == NULL && src == NULL)
		return (dest);
	tab2 = (const char *)src;
	tab = (char *)dest;
	i = 0;
	while (i < n)
	{
		tab[i] = tab2[i];
		i++;
	}
	return (dest);
}

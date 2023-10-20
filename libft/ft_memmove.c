/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:58:54 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/25 11:23:41 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tab;
	const char	*tab2;

	tab2 = (const char *)src;
	tab = (char *)dest;
	if (dest == src)
		return (dest);
	if (dest <= src)
		while (n--)
			*tab++ = *tab2++;
	else
		while (n--)
			tab[n] = tab2[n];
	return (dest);
}

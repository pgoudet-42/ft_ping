/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:55:15 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/29 09:44:28 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tab;
	void	*tab2;

	tab = (char *)s;
	i = 0;
	while (i < n && (tab[i] != (char)c))
	{
		i++;
	}
	tab2 = (void *)tab + i;
	if (i == n)
		return (NULL);
	else
		return (tab2);
}

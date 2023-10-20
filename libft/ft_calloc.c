/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:48:42 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/24 15:41:02 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	len;
	size_t	i;

	i = 0;
	len = nmemb * size;
	tab = malloc(len);
	if (tab != NULL)
	{
		while (len--)
		{
			tab[i] = 0;
			i++;
		}
	}
	return (tab);
}

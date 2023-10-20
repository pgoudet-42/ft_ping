/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:02:29 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/27 14:38:42 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*ptr_dest;
	size_t	free_space;

	ptr_dest = dst;
	free_space = dstsize;
	while (*ptr_dest && free_space != 0)
	{
		ptr_dest++;
		free_space--;
	}
	if (free_space == 0)
		return (ft_strlen(src) + dstsize);
	while (*src && free_space > 1)
	{
		*ptr_dest++ = *src++;
		free_space--;
	}
	*ptr_dest = 0;
	return (ft_strlen(dst) + ft_strlen(src));
}

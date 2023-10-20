/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:39:35 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/24 13:11:16 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*c;
	int		taille_src;
	int		i;

	taille_src = ft_strlen(src);
	i = 0;
	c = malloc(sizeof(char) * taille_src + 1);
	if (!c)
		return (NULL);
	while (i < taille_src)
	{
		c[i] = src[i];
		i++;
	}
	c[i] = 0;
	return (c);
}

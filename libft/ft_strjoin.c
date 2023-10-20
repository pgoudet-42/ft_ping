/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 14:47:17 by pgoudet           #+#    #+#             */
/*   Updated: 2021/01/29 13:50:59 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		len;

	i = -1;
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!tab)
		return (NULL);
	while (s1[++i])
		tab[i] = s1[i];
	len = -1;
	while (++len < (int)ft_strlen(s2))
		tab[i + len] = s2[len];
	tab[i + len] = 0;
	free(s1);
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:05:40 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/26 15:04:48 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tab;

	tab = (char *)s;
	while (*tab)
		tab++;
	while (*tab != (char)c && tab > s)
		tab--;
	if (*tab == (char)c)
		return (tab);
	return (NULL);
}

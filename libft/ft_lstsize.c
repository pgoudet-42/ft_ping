/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgoudet <pgoudet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:32:18 by pgoudet           #+#    #+#             */
/*   Updated: 2020/11/26 10:40:58 by pgoudet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*run;
	int		i;

	i = 1;
	if (lst == NULL)
		return (0);
	run = lst;
	while (run->next != NULL)
	{
		run = run->next;
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 03:25:50 by nait-bou          #+#    #+#             */
/*   Updated: 2023/11/22 04:12:04 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*s;
	int		i;

	s = lst;
	i = 0;
	if (!lst)
		return (0);
	while (s != NULL)
	{
		i++;
		s = s -> next;
	}
	return (i);
}

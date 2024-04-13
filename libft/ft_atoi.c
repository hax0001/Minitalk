/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hax <hax@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:32:53 by nait-bou          #+#    #+#             */
/*   Updated: 2024/04/13 15:39:32 by hax              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int formini(const char* str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (ft_strchr("abcdefghijklmnopqrstvwxyz", str[i]) != NULL)
			return(-1);
		if (ft_strchr("ABCDEFGHIJKLMNOPQRSTVWXYZ", str[i]) != NULL)
			return(-1);
		if ((str[i] >= 33 && str[i]<= 42) || (str[i] >= 44 && str[i]<= 47))
			return(-1);
		if ((str[i] >= 58 && str[i]<= 64) || (str[i] >= 91 && str[i]<= 96))
			return(-1);
		if (str[i] >= 123)
			return(-1);
		i++;
	}
	return(1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	if (formini(str) == -1)
		return(-1);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return(-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (str[i++] - '0') + (res * 10);
	return (res * neg);
}

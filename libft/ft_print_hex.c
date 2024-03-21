/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:33:40 by nait-bou          #+#    #+#             */
/*   Updated: 2024/03/21 11:16:46 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reverse(char *s)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(s);
	len--;
	while (i < len)
	{
		tmp = s[i];
		s[i] = s[len];
		s[len] = tmp;
		len--;
		i++;
	}
}

int	len_nbr(unsigned int n)
{
	long	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_print_hex(unsigned int n, int d)
{
	char	*result;
	long	i;
	int		len;

	if (n == 0)
		return (ft_print_char('0'), 1);
	i = 0;
	len = len_nbr(n) + 1;
	result = malloc(len);
	while (n)
	{
		if ((n % 16) >= 0 && (n % 16) <= 9)
			result[i++] = ((n % 16) + 48);
		else if ((n % 16) >= 10 && (n % 16) <= 15)
			result[i++] = ((n % 16) + d);
		n /= 16;
	}
	result[i] = '\0';
	reverse(result);
	ft_print_str(result);
	free(result);
	return (len - 1);
}

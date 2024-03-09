/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:09:34 by nait-bou          #+#    #+#             */
/*   Updated: 2023/12/12 22:43:58 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reverse(char *s)
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

static int	len_nbr(unsigned long n)
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

static int	ft_print_hp(unsigned long n, int d)
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

int	ft_print_pointer(unsigned long value)
{
	int	i;

	if (value == 0)
		return (ft_print_str("(nil)"));
	i = 0;
	i += ft_print_str("0x");
	i += ft_print_hp(value, 87);
	return (i);
}

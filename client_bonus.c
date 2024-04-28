/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:25:01 by nait-bou          #+#    #+#             */
/*   Updated: 2024/04/28 09:43:34 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	formini(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr("abcdefghijklmnopqrstvwxyz", str[i]) != NULL)
			return (-1);
		if (ft_strchr("ABCDEFGHIJKLMNOPQRSTVWXYZ", str[i]) != NULL)
			return (-1);
		if ((str[i] >= 33 && str[i] <= 42) || (str[i] >= 44 && str[i] <= 47))
			return (-1);
		if ((str[i] >= 58 && str[i] <= 64) || (str[i] >= 91 && str[i] <= 96))
			return (-1);
		if (str[i] >= 123)
			return (-1);
		i++;
	}
	return (1);
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
		return (-1);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (str[i++] - '0') + (res * 10);
	return (res * neg);
}

void	sms(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_putstr("       -------------        \n");
		ft_putstr(">>>>> | 3LA SLAMTEK | <<<<<\n");
		ft_putstr("       -------------        \n");
	}
}

void	ft_binary(int PID, char *str)
{
	int	bit;
	int	i;

	bit = 0;
	i = 0;
	while (1)
	{
		while (bit < 9)
		{
			if (str[i] & (128 >> bit))
				kill(PID, SIGUSR1);
			else
				kill(PID, SIGUSR2);
			bit++;
			usleep(300);
			if (bit == 8)
			{
				bit = 0;
				break ;
			}
		}
		if (!str[i])
			break ;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3 || av[2][0] == '\0')
	{
		ft_putstr("error\n");
		exit (1);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR2, sms);
	if (pid == -1)
	{
		ft_putstr("error\n");
		exit(1);
	}
	ft_binary(pid, av[2]);
}

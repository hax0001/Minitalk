/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hax <hax@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:49:29 by nait-bou          #+#    #+#             */
/*   Updated: 2024/03/15 04:22:35 by hax              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	ft_send(int pid, char data)
{
	int i;
	char bit;

	i = 0;
	while(i < 8)
	{
		bit = (data >> i) & 1;
		if(bit == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

int		main(int y, char **v)
{
	int		i;
	int		pid;

	i = 0;
	if (y == 3)
	{
		pid = ft_atoi(v[1]);
		while (v[2][i])
		{
			ft_send(pid, v[2][i]);
			i++;
		}
		ft_send(pid, 0);
	}
}
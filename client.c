/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:32:52 by nait-bou          #+#    #+#             */
/*   Updated: 2024/03/21 11:59:28 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char c)
{
	int		i;
	char	s;

	i = 7;
	while (i >= 0)
	{
		s = c >> i & 1;
		if (s == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
	{
		ft_printf("make sur to provid the PID and the message /n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
		send_message(pid, argv[2][i++]);
	send_message(pid, 10);
}
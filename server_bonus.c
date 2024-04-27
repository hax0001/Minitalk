/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:26:07 by nait-bou          #+#    #+#             */
/*   Updated: 2024/04/27 14:42:23 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, struct __siginfo *info, void *vo)
{
	static int	bit = 0;
	static char	c = 0xFF;
	static int	pid = 0;

	(void)*vo;	
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		c = 0xFF;
		bit = 0;
	}
	if (signum == SIGUSR1)
		c |= 128 >> bit;
	else
		c ^= 128 >> bit;
	if (++bit == 8)
	{
		if (!c)
		{
			kill(pid, SIGUSR2);
		}
		ft_putchar(c);
		bit = 0;
		c = 0xFF;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 1 || av[1] != NULL)
	{
		ft_putstr("error\n");
	}
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}

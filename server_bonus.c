/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 18:01:04 by nait-bou          #+#    #+#             */
/*   Updated: 2024/03/22 18:20:04 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	s = 0;

void	handler(int sig)
{
	static int	i = 0;
	s = s << 1 | (sig == SIGUSR1);
	i += 1;
	if (i == 8)
	{
		write(1, &s, 1);
		i = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("the PID of this server is %d\n", getpid());
	while (1)
	{
	}
}
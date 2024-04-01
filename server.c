/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:32:36 by nait-bou          #+#    #+#             */
/*   Updated: 2024/04/01 10:23:00 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

short	*g_s;

void	handler(int sig)
{
	*g_s = *g_s << 1 | (sig == SIGUSR1);
	*(g_s + 1) += 1;
	if (*(g_s + 1) == 8)
	{
		write(1, (char *)g_s, 1);
		*(g_s + 1) = 0;
	}
}

int	main(void)
{
	short	s;

	s = 0;
	g_s = &s;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("the PID of this server is %d\n", getpid());
	while (1)
	{
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:32:36 by nait-bou          #+#    #+#             */
/*   Updated: 2024/03/21 12:07:23 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

short	*s;

void	handler(int sig)
{
	*(char *)s = *(char *)s << 1 | (sig == SIGUSR1);
	*(char *)(s + 1) += 1;
	if (*(char *)((s + 1)) == 8)
	{
		write(1, (char *)s, 1);
		*(char *)((s + 1)) = 0;
	}
}

int	main(void)
{
	short	a;

	a = 0;
	s = &a;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("the PID of this server is %d\n", getpid());
	while (1)
	{
	}
}
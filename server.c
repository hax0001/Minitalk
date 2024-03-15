/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hax <hax@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:32:50 by nait-bou          #+#    #+#             */
/*   Updated: 2024/03/15 04:23:05 by hax              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

typedef struct s_data
{
	char	c;
	int		pos;
}				t_data;

t_data data;
void	ft_catch(int sig)
{
	if (sig == SIGUSR1)
		data.c |= 1 << data.pos; 
	data.pos++;
	if (data.pos == 8)
	{
		data.pos = 0;
		if (!data.c)
			ft_putchar('\n');
		else
			ft_putchar(data.c);
		data.c = 0;
	}
}

int		main()
{
	data.c = 0;
	data.pos = 0;
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, ft_catch);
	signal(SIGUSR2, ft_catch);
	while(1)
		pause();
	return (0);
}
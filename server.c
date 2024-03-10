/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:32:50 by nait-bou          #+#    #+#             */
/*   Updated: 2024/03/10 13:25:31 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void handler(int sig)
{
	
}

int main()
{	
	ft_printf("The PID of this server is : %d \n",getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(1){
	}
}
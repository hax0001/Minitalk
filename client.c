/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-bou <nait-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:49:29 by nait-bou          #+#    #+#             */
/*   Updated: 2024/03/09 20:08:23 by nait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void convert_message(int PID, char c)
{
	

}

int main(int argc, char **argv)
{
	int	PID;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("dkhl asahbi PID o message");    
	}
	PID = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		convert_message(PID, argv[2][i]);
		i++;
	}
}
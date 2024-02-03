/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:13:26 by moichou           #+#    #+#             */
/*   Updated: 2024/02/03 18:04:31 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(pid_t pid, char byte)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (byte >> i) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_putstr("Error : can't send signal to this process\n");
		}
		else if (bit == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_putstr("Error : can't send signal to this process\n");
		}
		usleep(420);
		i--;
	}
}

void	send_msg(pid_t pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		send_byte(pid, msg[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == 0 || pid == -1)
		{
			ft_putstr("Bad pid\n");
			return (0);
		}
		send_msg(pid, av[2]);
	}
	else
		ft_putstr("Error : no valid args");
}

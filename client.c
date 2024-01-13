/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:01:40 by moichou           #+#    #+#             */
/*   Updated: 2024/01/13 10:51:27 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	send_bytes(char byte)
{
	
}

int main(int ac, char **av)
{
	int	pid;
	if (ac >= 2)
	{
		pid = atoi(av[1]);
		if (pid == -1)
			return (0);
		else
			kill(pid, SIGUSR1);
	}
	else
		ft_printf("errrrrrror\n");
}
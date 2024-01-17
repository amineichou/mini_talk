/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:06:20 by moichou           #+#    #+#             */
/*   Updated: 2024/01/17 15:32:58 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void signal_handler(int signum)
{
	int count;
	char byte;
	int bit = 0;

	if (signum == SIGUSR1)
		bit = 1;
	else if (signum == SIGUSR2)
		bit = 0;
	byte = (byte << 1) | bit;
	count++;
	if (count == 8)
	{
		ft_printf("%c", byte);
		count = 0;
		byte = 0;
	}
}

int main(void)
{
	struct sigaction action;

	logo_design();
	ft_printf("PID is : \033[1;31m%d\033[0m\n\n", getpid());

	action.sa_handler = signal_handler;
	action.sa_flags = 0;
	action.sa_mask = 0;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ft_printf("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_printf("Failed to change SIGUSR2's behavior");

	while (1)
		pause();
	return 0;
}

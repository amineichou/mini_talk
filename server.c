/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:06:20 by moichou           #+#    #+#             */
/*   Updated: 2024/01/18 12:48:45 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./utils.c"

static void signal_handler(int signum)
{
	static int count;
	static char byte;
	int bit = 0;

	if (signum == SIGUSR1)
		bit = 1;
	else if (signum == SIGUSR2)
		bit = 0;
	byte = (byte << 1) | bit;
	count++;
	if (count == 8)
	{
		write(1, &byte, 1);
		count = 0;
		byte = 0;
	}
}

int main(void)
{
	struct sigaction action;
	pid_t pid;

	pid = getpid();
	logo_design();
	ft_printstr("PID is : \033[1;31m\033[0m");
	ft_putnbr(pid);
	ft_printstr("\n\n");
	action.sa_handler = signal_handler;
	action.sa_flags = 0;
	action.sa_mask = 0;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ft_printstr("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_printstr("Failed to change SIGUSR2's behavior");

	while (1)
		pause();
	return 0;
}

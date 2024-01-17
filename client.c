/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:01:40 by moichou           #+#    #+#             */
/*   Updated: 2024/01/17 15:31:48 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_byte(pid_t pid, char c)
{
    int bit;
    int i = 7;

    bit = 0;
    while (i >= 0)
    {
        bit = (c >> i) & 1;
        if (bit == 1)
            kill(pid, SIGUSR1);
        else if (bit == 0)
            kill(pid, SIGUSR2);
        usleep(420);
        i--;
    }
}

static void send_message(pid_t pid, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        send_byte(pid, str[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
        return (0);
    int pid =  ft_atoi(av[1]);
    if (pid == -1 || pid == 0)
    {
        return (0);
    }
    send_message(pid, av[2]);
}
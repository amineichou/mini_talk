/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 22:01:40 by moichou           #+#    #+#             */
/*   Updated: 2024/01/18 21:51:43 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./utils.c"

int received = 1;

static void send_byte(pid_t pid, char c)
{
    int bit;
    int i;

    bit = 0;
    i = 7;
    while (i >= 0)
    {
        if ((bit = (c >> i) & 1) == 1)
        {
            if (kill(pid, SIGUSR1) == -1)
            {
                received = 0;
                break;
            }
        }
        else if ((bit = (c >> i) & 1) == 0)
        {
            if (kill(pid, SIGUSR2) == -1)
            {
                received = 0;
                break;
            }
        }
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
        if (received == 0)
        {
            ft_printstr("error! not received\n");
            break;
        }
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
        ft_printstr("error process id\n");
        return (0);
    }
    send_message(pid, av[2]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:29:54 by moichou           #+#    #+#             */
/*   Updated: 2024/01/17 22:04:54 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

void	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
    write (1, &"0123456789"[n % 10], 1);
}

void logo_design(void)
{
	ft_printstr("\n");
	ft_printstr("███    ███ ██ ███    ██ ██     ████████  █████  ██      ██   ██ \n");
	ft_printstr("████  ████ ██ ████   ██ ██        ██    ██   ██ ██      ██  ██  \n");
	ft_printstr("██ ████ ██ ██ ██ ██  ██ ██        ██    ███████ ██      █████   \n");
	ft_printstr("██  ██  ██ ██ ██  ██ ██ ██        ██    ██   ██ ██      ██  ██  \n");
	ft_printstr("\033[1;31m██      ██ ██ ██   ████ ██        ██    ██   ██ ███████ ██   ██ \033[0m\n\n");
	ft_printstr("\n");
}
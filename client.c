/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:11:07 by baroun            #+#    #+#             */
/*   Updated: 2022/03/04 16:34:54 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_to_server(pid_t pid, char str)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((str >> i) & 1)
		{
			usleep(100);
			kill(pid, SIGUSR1);
		}
		else
		{
			usleep(100);
			kill(pid, SIGUSR2);
		}
		usleep(50);
		i++;
	}
}

int	ft_minitalk_error(int argc, char *argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Besoin de 2 args : PID & str\n", 1);
		return (0);
	}
	while (*argv)
	{
		if (!ft_isdigit(argv++))
		{
			ft_putstr_fd("Le PID doit etre un nombre", 1);
			return (0);
		}
	}
	retrun (1);
}

int	send_pidc(pid_t	pids, char pidc)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((pidc >> i) & 1)
		{
			usleep(100);
			kill(pidc, SIGUSR1);
		}
		else
		{
			usleep(100);
			kill(pidc, SIGUSR2);
		}
		usleep(50);
		i++;
	}
	
}

int	main(int argc, char **argv)
{
	int pids;
	char *pidc;

	pids = ft_atoi(argv[1]);
	pidc = malloc(sizeof(char) * count_nbr(getpid()));
	pidc = ft_itoa(getpid());
	if (!ft_minitalk_error(argc, argv[1]))
		return (0);
	while (*pidc)
		send_pidc(pids, pidc);
	while (*argv[2])
		send_to_server(pids, argv[2]++);
	return (1);
}

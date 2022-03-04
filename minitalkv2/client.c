/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:11:07 by baroun            #+#    #+#             */
/*   Updated: 2022/03/04 18:26:15 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	send_to_server(pid_t pid, char *str)
{
	int		i;
	char	c;

	i = 8;
	while (*str)
	{
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		while (i <= 8)
		{
			kill(pid, SIGUSR2);
			usleep(100);
			i++;
		}
	}
}

int	ft_minitalk_error(int argc, char *argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("Besoin de 2 args : PID & str\n", 1);
		return (0);
	}
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
		{
			ft_putstr_fd("Le PID doit etre un nombre", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int pids;
	int i;

	i = 0;
	pids = ft_atoi(argv[1]);
	if (ft_minitalk_error(argc, argv[1]) == 0)
		return (1);
	send_to_server(pids, argv[2]);
	return (0);
}

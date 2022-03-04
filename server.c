/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:28:54 by baroun            #+#    #+#             */
/*   Updated: 2022/03/04 17:05:30 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int pidc, int sig)
{
	static int	i;
	static int	c;

	i = 0;
	if (sig == SIGUSR1)
		c |= 1 << i;
	i++;

	if (i == 8)
	{
		write (1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	get_pidc(int sig)
{
	static int	c;
	static int	i;
	char		*pidc;

	while (c == '\0' || !ft_isdigit(c))
	{
		if (sig == SIGUSR1)
			c |= 1 << i;
		i++;
		if (i == 8)
		{
			pidc += c;
			i = 0;
			c = 0;
		}
	}

	return (ft_atoi(pidc));
}

int	main(void)
{
	struct sigaction	str;
	pid_t				pid;

	str.sa_flags = 0;
	str.sa_handler = sig_handler;
	ft_putnbr_fd(getpid(), 1);
	sigaction(SIGUSR1, &str, NULL);
	sigaction(SIGUSR2, &str, NULL);

	write(1, " ", 1);
	while (1)
		pause();
	return (0);
}

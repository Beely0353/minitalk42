/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:28:54 by baroun            #+#    #+#             */
/*   Updated: 2022/03/04 18:41:29 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

static void	sig_handler(int sig)
{
	static int	i;
	static unsigned char	c;

	i = 0;
	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	str;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	str.sa_handler = sig_handler;
	str.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &str, 0);
	sigaction(SIGUSR2, &str, 0);
	while (1)
		pause();
	return (0);
}

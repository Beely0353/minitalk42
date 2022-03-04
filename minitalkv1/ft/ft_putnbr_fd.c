/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:22:12 by baroun            #+#    #+#             */
/*   Updated: 2022/03/04 16:16:23 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	s;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		s = -n;
	}
	else
		s = n;
	if (s > 9)
	{
		ft_putnbr_fd(s / 10, fd);
		s %= 10;
	}
	ft_putchar_fd(s + '0', fd);
}

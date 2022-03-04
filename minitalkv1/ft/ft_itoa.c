/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:47:42 by baroun            #+#    #+#             */
/*   Updated: 2022/03/04 16:29:44 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	*ft_itoa(int n)
{
	char		*dst;
	int			i;
	long int	nbr;

	i = count_nbr(n);
	dst = malloc(i * sizeof(char) + 1);
	if (!dst)
		return (NULL);
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		dst[0] = '-';
	}
	dst[i--] = '\0';
	if (n == 0)
		dst[i] = '0';
	while (nbr)
	{
		dst[i] = '0' + nbr % 10;
		nbr /= 10;
		i--;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:15:13 by baroun            #+#    #+#             */
/*   Updated: 2021/10/28 16:42:05 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*dst;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1);
	while (is_in_set(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
	{
		dst = ft_strdup("");
		return (dst);
	}
	while (is_in_set(s1[end - 1], set))
		end--;
	dst = ft_substr(s1, start, end - start);
	return (dst);
}

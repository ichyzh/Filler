/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:01:55 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:02:11 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*s1;
	const char	*s2;

	s1 = (char*)dst;
	s2 = (const char*)src;
	i = 0;
	if (s2 > s1)
	{
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	i = len;
	if (s2 < s1)
	{
		while (i > 0)
		{
			s1[i - 1] = s2[i - 1];
			i--;
		}
	}
	return (dst);
}

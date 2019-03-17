/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:59:52 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:00:04 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*t1;
	unsigned char	*t2;

	i = 0;
	d = (unsigned char)c;
	t1 = (unsigned char*)dest;
	t2 = (unsigned char*)src;
	while (i < n)
	{
		t1[i] = t2[i];
		if (t1[i] == d)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}

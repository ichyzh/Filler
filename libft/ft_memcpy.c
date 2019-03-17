/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:01:30 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:01:40 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char*)dest;
	t2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		t1[i] = t2[i];
		i++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:00:31 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:00:47 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	d;

	t1 = (unsigned char*)s;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (t1[i] == d)
			return (t1 + i);
		i++;
	}
	return (NULL);
}

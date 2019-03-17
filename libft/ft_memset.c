/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:02:27 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:02:48 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	t2;

	t1 = (unsigned char*)s;
	t2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		t1[i] = t2;
		i++;
	}
	return (t1);
}

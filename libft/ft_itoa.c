/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:25:36 by ichyzh            #+#    #+#             */
/*   Updated: 2017/12/06 14:42:43 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	size_t			l;
	unsigned int	m;

	m = n;
	l = ft_get_int_len(n);
	if (!(str = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	str[l] = '\0';
	if (n < 0)
	{
		m = -n;
		str[0] = '-';
	}
	else if (n == 0)
		str[0] = '0';
	while (m)
	{
		str[--l] = m % 10 + '0';
		m /= 10;
	}
	return (str);
}

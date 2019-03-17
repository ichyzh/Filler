/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:03:59 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:04:10 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	i = 0;
	while (t1[i] && t2[i] && t1[i] == t2[i])
		i++;
	return (t1[i] - t2[i]);
}

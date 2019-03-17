/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:09:29 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:09:37 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	int		i;
	char	t;

	r = (char*)s;
	t = (char)c;
	i = 0;
	while (r[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (r[i] == t)
		{
			return (r + i);
		}
		i--;
	}
	return (NULL);
}

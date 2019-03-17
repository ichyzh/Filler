/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strn_char_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:54:57 by ichyzh            #+#    #+#             */
/*   Updated: 2018/06/10 15:55:00 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strn_char_new(ssize_t size, char c)
{
	char	*str;
	ssize_t	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

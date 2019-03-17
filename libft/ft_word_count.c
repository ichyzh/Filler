/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:12:12 by ichyzh            #+#    #+#             */
/*   Updated: 2017/12/15 16:12:20 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(const char *s, char d)
{
	int i;
	int count;
	int word;

	i = 0;
	count = 0;
	while (s[i])
	{
		word = 0;
		while (s[i] && s[i] == d)
			i++;
		while (s[i] && s[i] != d)
		{
			i++;
			word = 1;
		}
		if (word == 1)
			count++;
	}
	return (count);
}

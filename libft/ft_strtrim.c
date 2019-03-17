/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:22:21 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:22:37 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		n;
	char	*str;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(s);
	while (++i <= n)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		if (i == n)
			return (ft_strnew(0));
		while (s[n - 1] == ' ' || s[n - 1] == '\t' || s[n - 1] == '\n')
			n--;
		if (!(str = (char*)malloc(sizeof(*str) * (n - i + 1))))
			return (NULL);
		while (s[i] != '\0' && i < n)
			str[j++] = s[i++];
		str[j] = '\0';
	}
	return (str);
}

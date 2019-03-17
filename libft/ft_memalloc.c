/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:13:05 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:13:15 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*fresh;

	if (!(fresh = (void*)malloc(sizeof(*fresh) * (size))))
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}

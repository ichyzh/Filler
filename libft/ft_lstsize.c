/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:26:31 by ichyzh            #+#    #+#             */
/*   Updated: 2017/12/15 16:27:25 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *begin_list)
{
	int		count;
	t_list	*list;

	count = 0;
	list = begin_list;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:21:11 by ichyzh            #+#    #+#             */
/*   Updated: 2017/12/01 16:22:58 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;
	t_list *res;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = f(lst);
	if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lst = lst->next;
	res = new;
	while (lst)
	{
		tmp = f(lst);
		if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (res);
}

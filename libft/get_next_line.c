/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:45:45 by ichyzh            #+#    #+#             */
/*   Updated: 2018/03/14 16:45:53 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_glist	*ft_new_glist(int fd)
{
	t_glist *list;

	if (!(list = (t_glist*)malloc(sizeof(t_glist))))
		return (NULL);
	list->fd = fd;
	list->str = ft_strnew(0);
	list->next = NULL;
	return (list);
}

void	ft_list_push_back(t_glist **begin_list, t_glist *temp)
{
	t_glist *tmp;

	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = temp;
}

t_glist	*ft_push_fd_list(t_glist **list, int fd)
{
	t_glist	*tmp;
	t_glist	*back;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	back = ft_new_glist(fd);
	ft_list_push_back(list, back);
	return (back);
}

int		ft_endl(t_glist **list, char **line, int ret)
{
	char	*end;
	size_t	len;
	char	*tmp;

	len = ft_strlen((*list)->str);
	if (((end = ft_strchr((*list)->str, '\n')) != NULL))
	{
		tmp = ft_strsub((*list)->str, len - ft_strlen(end), len);
		*end = '\0';
		*line = ft_strdup((*list)->str);
		ft_strdel(&(*list)->str);
		(*list)->str = ft_strdup(tmp + 1);
		ft_strdel(&tmp);
		return (1);
	}
	else if (ret == 0 && len > 0)
	{
		*line = ft_strdup((*list)->str);
		ft_strdel(&(*list)->str);
		return (1);
	}
	*line = NULL;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;
	static t_glist	*glist = NULL;
	t_glist			*tempo;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!glist)
		glist = ft_new_glist(fd);
	tempo = ft_push_fd_list(&glist, fd);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = tempo->str;
		tempo->str = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
		if (ft_endl(&tempo, line, ret) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (ret == 0)
		return (ft_endl(&tempo, line, ret));
	return (0);
}

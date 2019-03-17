/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:46:35 by ichyzh            #+#    #+#             */
/*   Updated: 2018/06/10 18:46:39 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_clear_arr(char **arr)
{
	size_t count;

	count = 0;
	while (arr[count])
	{
		free(arr[count]);
		arr[count] = NULL;
		count++;
	}
	free(arr);
	arr = NULL;
}

void		print_res(t_fin fin, t_token *t)
{
	ft_putnbr(fin.y - t->min_y);
	write(1, " ", 1);
	ft_putnbr(fin.x - t->min_x);
	write(1, "\n", 1);
	ft_clear_arr(t->map);
}

void		init_filler_s(t_filler *s)
{
	s->pnum = 0;
	s->pchar = 0;
	s->ochar = 0;
	s->x = 0;
	s->y = 0;
	s->map = NULL;
	s->step = 0;
}

void		init_token_s(t_token *t)
{
	t->x = 0;
	t->y = 0;
	t->min_x = 99;
	t->min_y = 100;
	t->max_x = 0;
	t->max_y = 0;
	t->map = NULL;
}

void		get_player_num(t_filler *s)
{
	char	*line;

	get_next_line(0, &line);
	s->pnum = ft_atoi(&line[10]);
	free(line);
	s->pchar = (s->pnum == 1) ? 'O' : 'X';
	s->ochar = (s->pnum == 1) ? 'X' : 'O';
}

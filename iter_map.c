/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:48:47 by ichyzh            #+#    #+#             */
/*   Updated: 2018/06/10 18:48:48 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_fin_s(t_fin *fin)
{
	fin->x = 100;
	fin->y = 99;
	fin->length = 199;
}

int		find_overlap(int y, int x, t_filler f, t_token *t)
{
	int		overlap;
	int		r;
	int		c;
	int		tmp_x;

	c = t->min_y;
	overlap = 0;
	tmp_x = x;
	while (y < f.y && c <= t->max_y)
	{
		r = t->min_x - 1;
		x = tmp_x - 1;
		while (++x < f.x && ++r <= t->max_x)
		{
			if (f.map[y][x] == f.pchar && t->map[c][r] == '*')
				overlap++;
			if (overlap > 1 || ((f.map[y][x] == 'K' || f.map[y][x] == f.ochar)
				&& t->map[c][r] == '*'))
				return (0);
		}
		y++;
		c++;
	}
	return (overlap);
}

int		paste_token(int y, int x, t_filler f, t_token *t)
{
	int		overlap;

	overlap = 0;
	if ((((f.x - x)) < t->max_x - t->min_x + 1) ||
		((f.y - y) < t->max_y - t->min_y + 1))
		return (0);
	overlap = find_overlap(y, x, f, t);
	if (overlap == 1)
		return (1);
	return (0);
}

int		find_op_coor(t_filler f, t_fin *fin, int y, int x)
{
	int		j;
	int		i;
	char	ochar;
	int		counter;
	int		length;

	ochar = f.step > 0 ? 'K' : 'X';
	i = 0;
	counter = 0;
	while (i < f.y)
	{
		j = 0;
		while (j < f.x)
		{
			if (f.map[i][j] == ochar)
			{
				if ((length = find_min_length(i, j, y, x)) < fin->length)
					write_length(y, x, fin, length);
				counter = 1;
			}
			j++;
		}
		i++;
	}
	return (counter);
}

int		iter_map(t_filler f, t_token *t, t_fin *fin)
{
	int		x;
	int		y;
	int		counter;

	y = -1;
	find_token_min(t);
	find_token_max(t);
	init_fin_s(fin);
	counter = 0;
	while (++y < f.y)
	{
		x = -1;
		while (++x < f.x)
		{
			if (paste_token(y, x, f, t))
			{
				find_op_coor(f, fin, y, x);
				counter = 1;
			}
		}
	}
	if (counter == 1)
		return (1);
	return (0);
}

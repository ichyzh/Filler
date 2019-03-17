/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:47:46 by ichyzh            #+#    #+#             */
/*   Updated: 2018/06/10 18:47:49 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_min_length(int i, int j, int y, int x)
{
	int length_y;
	int length_x;
	int length;

	length_y = (i - y);
	length_x = (j - x);
	length_y = length_y < 0 ? -length_y : length_y;
	length_x = length_x < 0 ? -length_x : length_x;
	length = length_y + length_x;
	return (length);
}

void	write_length(int y, int x, t_fin *fin, int length)
{
	fin->x = x;
	fin->y = y;
	fin->length = length;
}

void	find_token_min(t_token *t)
{
	int	x;
	int	y;

	y = 0;
	while (y < t->y)
	{
		x = 0;
		while (x < t->x)
		{
			if (t->map[y][x] == '*')
			{
				if (x < t->min_x)
					t->min_x = x;
				if (y < t->min_y)
					t->min_y = y;
			}
			x++;
		}
		y++;
	}
}

void	find_token_max(t_token *t)
{
	int	x;
	int	y;

	y = t->y - 1;
	while (y >= 0)
	{
		x = t->x - 1;
		while (x >= 0)
		{
			if (t->map[y][x] == '*')
			{
				if (x > t->max_x)
					t->max_x = x;
				if (y > t->max_y)
					t->max_y = y;
			}
			x--;
		}
		y--;
	}
}

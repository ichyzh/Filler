/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:47:17 by ichyzh            #+#    #+#             */
/*   Updated: 2018/06/10 18:47:19 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		**slap_map(char **new_map, t_filler *s)
{
	int	x;
	int	y;

	y = 0;
	s->step = 0;
	while (y < s->y)
	{
		x = 0;
		while (x < s->x)
		{
			if (new_map[y][x] == s->ochar && s->map[y][x] == '.')
			{
				new_map[y][x] = 'K';
				s->step++;
			}
			x++;
		}
		y++;
	}
	ft_clear_arr(s->map);
	return (new_map);
}

char		**write_map(t_filler *s)
{
	char	**new_map;
	char	*line;
	int		i;

	i = 0;
	if (s->map == NULL)
	{
		s->map = (char **)malloc(sizeof(char *) * (s->y + 1));
		while (i < s->y)
		{
			s->map[i] = ft_strn_char_new(s->x, '.');
			i++;
		}
		s->map[i + 1] = NULL;
	}
	i = -1;
	new_map = (char **)malloc(sizeof(char *) * (s->y + 1));
	while (++i < s->y)
	{
		get_next_line(0, &line);
		new_map[i] = ft_strdup(&line[4]);
		free(line);
	}
	new_map[i] = NULL;
	return (slap_map(new_map, s));
}

void		get_map_size(t_filler *s)
{
	char	**split;
	char	*line;

	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	s->y = ft_atoi(split[1]);
	s->x = ft_atoi(split[2]);
	free(line);
	ft_clear_arr(split);
	get_next_line(0, &line);
	free(line);
}

t_token		get_token(void)
{
	char	*line;
	char	**split;
	int		i;
	t_token	t;

	i = 0;
	init_token_s(&t);
	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	t.y = ft_atoi(split[1]);
	t.x = ft_atoi(split[2]);
	free(line);
	ft_clear_arr(split);
	if (t.map != NULL)
		ft_clear_arr(t.map);
	t.map = (char **)malloc(sizeof(char *) * (t.y + 1));
	while (i < t.y)
	{
		get_next_line(0, &line);
		t.map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	t.map[i] = NULL;
	return (t);
}

int			main(void)
{
	t_filler	s;
	t_token		t;
	t_fin		fin;
	int			res;

	init_filler_s(&s);
	get_player_num(&s);
	res = 1;
	while (res == 1)
	{
		get_map_size(&s);
		s.map = write_map(&s);
		t = get_token();
		res = iter_map(s, &t, &fin);
		if (res == 0)
		{
			ft_clear_arr(s.map);
			ft_clear_arr(t.map);
			write(1, "0 0\n", 4);
			return (0);
		}
		print_res(fin, &t);
	}
	return (0);
}

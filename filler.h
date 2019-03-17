/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:47:17 by ichyzh            #+#    #+#             */
/*   Updated: 2018/06/10 18:47:19 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./libft/includes/libft.h"

typedef	struct		s_filler
{
	int				pnum;
	char			pchar;
	char			ochar;
	int				x;
	int				y;
	char			**map;
	int				step;
}					t_filler;

typedef	struct		s_token
{
	int				x;
	int				y;
	int				min_x;
	int				max_x;
	int				max_y;
	int				min_y;
	char			**map;
}					t_token;

typedef	struct		s_fin
{
	int				x;
	int				y;
	int				length;
}					t_fin;

void				ft_clear_arr(char **arr);
void				get_map_size(t_filler *s);
void				get_player_num(t_filler *s);
t_token				get_token(void);
char				**write_map(t_filler *s);
char				**slap_map(char **new_map, t_filler *s);
int					iter_map(t_filler f, t_token *t, t_fin *fin);
int					find_op_coor(t_filler f, t_fin *fin, int y, int x);
int					find_min_length(int i, int j, int y, int x);
int					find_overlap(int y, int x, t_filler f, t_token *t);
void				print_res(t_fin fin, t_token *t);
int					paste_token(int y, int x, t_filler f, t_token *t);
void				find_token_max(t_token *t);
void				find_token_min(t_token *t);
void				init_filler_s(t_filler *s);
void				init_fin_s(t_fin *fin);
void				init_token_s(t_token *t);
void				write_length(int y, int x, t_fin *fin, int length);

#endif

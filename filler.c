/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 04:03:58 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/15 04:04:31 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	allocate_coor(t_v *v)
{
	char	*line;

	get_next_line(0, &line);
	v->dim_py = ft_atoi(&line[5]);
	v->dim_px = ft_atoi(&line[8]);
	ft_strdel(&line);
	v->coor = (int *)malloc(sizeof(int) * ((v->dim_py * v->dim_px * 2)));
}

void	get_piece_coor(t_v *v)
{
	char	*line;
	char	*t;
	int		i;
	int		n;

	i = -1;
	v->c = 0;
	allocate_coor(v);
	while (++i < v->dim_py && get_next_line(0, &line) == 1)
	{
		n = -1;
		while (line[++n])
		{
			if (line[n] == '*')
			{
				v->coor[v->c] = n;
				v->coor[v->c + 1] = i;
				v->c += 2;
			}
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

int		filler_continue(t_v *v)
{
	get_piece_coor(v);
	if (v->ply == 'x' && v->dim_ty == 24)
	{
		check_height_level(v);
		check_right_level(v);
		check_left_level(v);
		if ((v->left_move == 1 && !check_left_side(v)))
			set_left_map(v);
		else if (v->height_move == 1 && !check_high_side(*v))
			set_height_map(v);
		else if (v->right_move == 1 && !check_right_side(v) &&
														!check_high_side(*v))
			set_right_map(v);
		else
			heat_map(v);
	}
	else
		heat_map(v);
	check_pp(v);
	return (1);
}

int		filler(t_v *v, int count)
{
	char	*line;
	char	*t;
	int		i;
	int		j;

	if ((i = -1) && count > 0 && (get_next_line(0, &line)))
		ft_strdel(&line);
	if (get_next_line(0, &line) == 1)
	{
		ft_strdel(&line);
		while (++i < v->dim_ty && get_next_line(0, &line) == 1)
		{
			j = -1;
			while (line[++j + 4])
			{
				v->tab[i][j] = (line[j + 4] == '.' ? 0 : -1);
				(ft_tolower(line[j + 4]) != v->ply && line[j + 4] != '.') ?
														(v->tab[i][j] = 1) : 0;
			}
			ft_strdel(&line);
		}
	}
	else
		return (0);
	return (filler_continue(v));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point_coor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:05:23 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/02 09:58:48 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**  return (-1) the shape is bigger than the map
**  return (-2) the asterisk has contact with the adversary
**  return (-3) the asterisk has no connections with my characters
**  return (-4) the asterisk has more than one connecton with my charcs
*/

int	check_point(t_v *v, int x, int y)
{
	int i;
	int con;
	int value;

	i = 0;
	value = 0;
	con = 0;
	while (i < v->c)
	{
		if (v->dim_ty - 1 < y + v->coor[i + 1] ||
												v->dim_tx - 1 < x + v->coor[i])
			return (-1);
		if (v->tab[y + v->coor[i + 1]][x + v->coor[i]] == 1)
			return (-2);
		if (v->tab[y + v->coor[i + 1]][x + v->coor[i]] == -1)
			con++;
		if (v->tab[y + v->coor[i + 1]][x + v->coor[i]] > 1)
			value += v->tab[y + v->coor[i + 1]][x + v->coor[i]];
		i += 2;
	}
	if (con == 0)
		return (-3);
	if (con > 1)
		return (-4);
	return (value);
}

int	check_pp(t_v *v)
{
	int x;
	int y;
	int tmp;

	y = -1;
	v->sum = __INT_MAX__;
	v->p.y = 0;
	v->p.x = 0;
	while (++y < v->dim_ty)
	{
		x = -1;
		while (++x < v->dim_tx && ((tmp = check_point(v, x, y)) || 1))
		{
			if ((tmp < v->sum && tmp > 0 && v->ply == 'x') ||
					(tmp <= v->sum && tmp > 0 && v->ply == 'o'))
			{
				v->sum = tmp;
				v->p.x = x;
				v->p.y = y;
			}
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sides.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:06:24 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/02 09:50:09 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_low_side(t_v v)
{
	int j;

	j = -1;
	while (++j < v.dim_tx)
	{
		if (v.tab[v.dim_ty - 1][j] == -1)
			return (1);
	}
	return (0);
}

int	check_high_side(t_v v)
{
	int j;

	j = -1;
	while (++j < v.dim_tx)
	{
		if (v.tab[0][j] == -1)
			return (1);
	}
	return (0);
}

int	check_right_side(t_v *v)
{
	int i;

	i = -1;
	while (++i < v->dim_ty)
	{
		if (v->tab[i][v->dim_tx - 1] == -1)
			return (1);
	}
	return (0);
}

int	check_left_side(t_v *v)
{
	int j;

	j = -1;
	while (++j < v->dim_ty)
	{
		if (v->tab[j][0] == -1)
		{
			return (1);
		}
	}
	return (0);
}

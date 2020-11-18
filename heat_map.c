/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:23:14 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/13 20:32:50 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define VLD(X, L)  (X != 0 && X != -1 && X != L) ? 1 : 0

void	set_case(t_v *v, int i, int j, int layern)
{
	if (i > 0 && j > 0 && VLD(v->tab[i - 1][j - 1], layern))
		v->tab[i][j] = layern;
	else if (i > 0 && j < v->dim_tx - 1 && VLD(v->tab[i - 1][j + 1], layern))
		v->tab[i][j] = layern;
	else if (i > 0 && VLD(v->tab[i - 1][j], layern))
		v->tab[i][j] = layern;
	else if (i < v->dim_ty - 1 && j > 0 && VLD(v->tab[i + 1][j - 1], layern))
		v->tab[i][j] = layern;
	else if (i < v->dim_ty - 1 && j < v->dim_tx - 1 && VLD(v->tab[i + 1][j + 1],
																		layern))
		v->tab[i][j] = layern;
	else if (i < v->dim_ty - 1 && VLD(v->tab[i + 1][j], layern))
		v->tab[i][j] = layern;
	else if (j > 0 && VLD(v->tab[i][j - 1], layern))
		v->tab[i][j] = layern;
	else if (j < v->dim_tx - 1 && VLD(v->tab[i][j + 1], layern))
		v->tab[i][j] = layern;
}

int		set_layer(t_v *v, int layern)
{
	int i;
	int j;
	int zr;

	zr = 0;
	i = -1;
	while (++i < v->dim_ty)
	{
		j = -1;
		while (++j < v->dim_tx)
		{
			if (v->tab[i][j] == 0)
			{
				set_case(v, i, j, layern);
				if (v->tab[i][j] == layern)
					zr = 1;
			}
		}
	}
	return (zr);
}

void	set_restofmap(t_v *v, int layern)
{
	int i;
	int j;

	i = -1;
	while (++i < v->dim_ty)
	{
		j = -1;
		while (++j < v->dim_tx)
		{
			if (v->tab[i][j] == 0)
				v->tab[i][j] = layern;
		}
	}
}

void	heat_map(t_v *v)
{
	int	layern;

	layern = 2;
	while ((set_layer(v, layern)))
		layern++;
	set_restofmap(v, layern);
}

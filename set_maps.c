/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_maps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:00:23 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/02 10:12:52 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_right_map(t_v *v)
{
	int i;
	int j;
	int coef;

	i = -1;
	coef = 10;
	while (++i < v->dim_ty)
	{
		j = -1;
		while (++j < v->dim_tx)
		{
			if (v->tab[i][j] == 0)
				v->tab[i][j] = (v->dim_tx - j + 1) * coef;
		}
		coef += 4;
	}
}

void	set_height_map(t_v *v)
{
	int i;
	int j;
	int layn;

	i = -1;
	layn = 2;
	while (++i < v->dim_ty)
	{
		j = -1;
		while (++j < v->dim_tx)
		{
			if (v->tab[i][j] == 0)
				v->tab[i][j] = layn;
		}
		layn++;
	}
}

void	set_left_map(t_v *v)
{
	int i;
	int j;
	int coef;

	i = -1;
	coef = v->dim_ty;
	while (++i < v->dim_ty)
	{
		j = -1;
		while (++j < v->dim_tx)
		{
			if (v->tab[i][j] == 0)
				v->tab[i][j] = (j + 2);
		}
		coef--;
	}
}

void	set_lowering_map(t_v *v)
{
	int i;
	int j;
	int layn;

	i = -1;
	layn = v->dim_ty + 2;
	while (++i < v->dim_ty)
	{
		j = -1;
		while (++j < v->dim_tx)
		{
			if (v->tab[i][j] == 0)
				v->tab[i][j] = layn;
		}
		layn--;
	}
}

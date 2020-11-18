/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:34:47 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/02 09:51:52 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	check_lowering_level(t_v *v)
{
	int i;
	int j;

	i = -1;
	while (++i < v->dim_ty)
	{
		j = -1;
		while (++j < v->dim_tx)
		{
			if (v->tab[i][j] == 1 && i < v->dim_ty - 1 && v->dim_ty - j <=
								(v->dim_ty / 10) * 3 && v->tab[i + 1][j] == 1)
				v->lowering_move = 1;
		}
	}
}

void	check_left_level(t_v *v)
{
	int i;
	int j;
	int me;

	i = -1;
	me = 0;
	while (++i < v->dim_ty)
	{
		j = -1;
		while (++j < v->dim_tx)
		{
			if (v->tab[i][j] == -1 && j >= 1 && j <=
								(v->dim_tx / 10) * 3 && v->tab[i][j - 1] == 1)
			{
				v->left_move = 0;
				return ;
			}
			if (v->tab[i][j] == -1)
				me = j;
		}
	}
	me != 0 ? v->left_move = 1 : 0;
}

void	check_right_level(t_v *v)
{
	int i;
	int j;

	i = -1;
	if (v->height_move == 1)
		return ;
	while (++i < v->dim_ty)
	{
		j = -1;
		while (++j < v->dim_tx)
		{
			if (v->tab[i][j] == -1 && i >= 1 && i <= v->dim_ty / 10
													&& v->tab[i - 1][j] == 1)
				v->right_move = 1;
		}
	}
}

void	check_height_level(t_v *v)
{
	int i;
	int j;
	int me;

	i = -1;
	me = 0;
	while (++i < v->dim_ty)
	{
		j = -1;
		while (++j < v->dim_tx)
		{
			if (v->tab[i][j] == -1 && i >= 1 && i <= v->dim_ty / 10
													&& v->tab[i - 1][j] == 1)
			{
				v->height_move = 0;
				return ;
			}
			if (v->tab[i][j] == -1 && !me)
				me = i;
		}
	}
	me != 0 ? v->height_move = 1 : 0;
}

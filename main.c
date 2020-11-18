/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:10:22 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/15 04:04:34 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		allocate_tab(t_v *v, int i)
{
	char *line;

	get_next_line(0, &line);
	v->dim_ty = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	v->dim_tx = ft_atoi(&line[i]);
	ft_strdel(&line);
	i = -1;
	if (!(v->tab = (int **)malloc(sizeof(int*) * (v->dim_ty))))
		return (1);
	while (++i < v->dim_ty)
		v->tab[i] = (int*)malloc(sizeof(int) * (v->dim_tx));
	return (0);
}

int		main(void)
{
	char	*line;
	int		i;
	t_v		v;
	int		count;

	count = 0;
	v.right_move = 0;
	v.height_move = 0;
	v.left_move = 0;
	get_next_line(0, &line);
	v.ply = (line[10] == '1') ? 'o' : 'x';
	i = 8;
	ft_strdel(&line);
	if (allocate_tab(&v, i))
		return (0);
	while (filler(&v, count++))
		ft_printf("%d %d\n", v.p.y, v.p.x);
	i = -1;
	while (++i < v.dim_ty)
		free(v.tab[i]);
	free(v.tab);
	free(v.coor);
	return (0);
}

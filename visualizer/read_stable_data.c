/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stable_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 21:57:14 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/15 03:24:27 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

char	*get_player_name(char const *s)
{
	char	*pname;
	int		i;
	int		len;
	int		j;

	i = -1;
	len = 0;
	while (s[++i] != '/')
		;
	j = i;
	while (s[++j] != '.')
		len++;
	return (ft_strsub(s, 23, len));
}

int		read_stable_data_2(t_v *v, int i)
{
	char *line;

	get_next_line(0, &line);
	v->dim_ty = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	v->dim_tx = ft_atoi(&line[i]);
	if (!(v->tab = (int **)malloc(sizeof(int*) * (v->dim_ty))))
		return (0);
	i = -1;
	while (++i < v->dim_ty)
		v->tab[i] = (int*)malloc(sizeof(int) * (v->dim_tx));
	ft_strdel(&line);
	return (1);
}

int		read_stable_data(t_v *v)
{
	char	*line;
	char	*t;
	int		i;

	i = 6;
	if (!(get_next_line(0, &line)))
		return (0);
	while ((t = line) && get_next_line(0, &line) == 1 && --i)
		ft_strdel(&t);
	if (!ft_strcmp(line, "bad player"))
		return (-1);
	v->p1_name = get_player_name((char const *)line);
	ft_strdel(&line);
	ft_strdel(&t);
	get_next_line(0, &line);
	ft_strdel(&line);
	get_next_line(0, &line);
	v->p2_name = get_player_name((char const *)line);
	i = 8;
	if (!ft_strcmp(line, "bad player"))
		return (-1);
	ft_strdel(&line);
	return (read_stable_data_2(v, i));
}

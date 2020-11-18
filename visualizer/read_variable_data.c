/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_variable_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 03:24:09 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/16 02:51:26 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

char	*incr_duplicate_piece(void)
{
	char *line;
	char *t;

	if (!(get_next_line(0, &line)))
		return (NULL);
	while ((t = line) && (line[0] == '*' || line[0] == '.')
			&& get_next_line(0, &line) == 1)
		ft_strdel(&t);
	ft_strdel(&line);
	get_next_line(0, &line);
	return (line);
}

char	*incr_piece(void)
{
	char	*line;
	int		incr;

	incr = 0;
	if (get_next_line(0, &line) == 1)
		incr = ft_atoi(&line[5]) + 1;
	ft_strdel(&line);
	while (incr-- && get_next_line(0, &line) == 1)
		ft_strdel(&line);
	if (get_next_line(0, &line) == 1 && *line && line[1] == 'i')
	{
		ft_strdel(&line);
		return (incr_duplicate_piece());
	}
	return (line);
}

int		get_final_score(t_v *v, char *line)
{
	v->p1sc = ft_atoi(&line[10]);
	ft_strdel(&line);
	get_next_line(0, &line);
	v->p2sc = ft_atoi(&line[10]);
	ft_strdel(&line);
	return (0);
}

int		read_variable_data(t_v *v, int count)
{
	char	*line;
	int		i;
	int		j;

	i = -1;
	if (!get_next_line(0, &line))
		return (0);
	ft_strdel(&line);
	while (++i < v->dim_ty && get_next_line(0, &line) == 1)
	{
		j = -1;
		while (line[++j + 4])
			v->tab[i][j] = line[j + 4];
		ft_strdel(&line);
	}
	line = incr_piece();
	if (line[0] == '=')
		return (get_final_score(v, line));
	ft_strdel(&line);
	return (1);
}

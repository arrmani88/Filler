/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 03:55:24 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/16 05:54:47 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "SDL_ttf.h"

void	set_display_dimensions(t_v *v)
{
	v->diff_i = 51;
	v->diff_j = 51;
	v->rec_surf = 45;
	v->angle = 4;
	v->corner_i = 270;
	v->corner_j = 185;
	if (v->dim_ty == 24)
	{
		v->diff_i = 21;
		v->diff_j = 21;
		v->rec_surf = 18;
		v->angle = 2;
		v->corner_i = 300;
		v->corner_j = 185;
	}
	else if (v->dim_ty == 100)
	{
		v->diff_i = 8;
		v->diff_j = 8;
		v->rec_surf = 7;
		v->angle = 1;
		v->corner_i = 215;
		v->corner_j = 175;
	}
}

void	set_map_details(t_v *v)
{
	if (v->dim_ty == 100)
		v->map_name = ft_strdup("MAP02 (100x99)");
	if (v->dim_ty == 24)
		v->map_name = ft_strdup("MAP01 (24x40)");
	if (v->dim_ty == 15)
		v->map_name = ft_strdup("MAP00 (15x17)");
}

void	set_display(t_v *v, t_sdlvar *sv)
{
	int count;

	count = 0;
	sv->quit = update_input();
	read_variable_data(v, count);
	count++;
	draw_image(sv->ren, sv->img, sv->pos);
	draw_rect(sv->ren, *v);
	wrt(sv->ren, v->map_name, 350, sv->lightb);
	wrt(sv->ren, v->p1_name, 500, sv->gr);
	if (v->p1sc != -1)
		wrt(sv->ren, ft_itoa(v->p1sc), 600, sv->gr);
	wrt(sv->ren, v->p2_name, 810, sv->y);
	if (v->p2sc != -1)
		wrt(sv->ren, ft_itoa(v->p2sc), 910, sv->y);
	SDL_UpdateWindowSurface(sv->win);
	SDL_RenderPresent(sv->ren);
}

void	set_initial_variables(t_sdlvar *sv, t_v *v)
{
	sv->lightb = (SDL_Color){0xcd, 0xc9, 0xd1};
	sv->y = (SDL_Color){0xe6, 0xff, 0xc8};
	sv->gr = (SDL_Color){0x0, 0x9f, 0x9d};
	sv->pos = (SDL_Rect){0, 0, 5, 5};
	sv->quit = SDL_FALSE;
	sv->win = NULL;
	sv->ren = NULL;
	v->p1sc = -1;
	v->p2sc = -1;
}

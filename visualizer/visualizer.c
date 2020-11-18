/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 23:48:22 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/16 05:57:27 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "SDL_ttf.h"

#define W_W 1920
#define W_H 1080

int		update_input(void)
{
	SDL_Event	event;
	SDL_bool	quit;

	quit = SDL_FALSE;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			quit = SDL_TRUE;
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				quit = SDL_TRUE;
		}
	}
	return (quit);
}

void	liberate_memory(t_v *v, t_sdlvar *sv)
{
	int i;

	i = -1;
	while (++i < v->dim_ty)
		free(v->tab[i]);
	free(v->tab);
	ft_strdel(&v->p1_name);
	ft_strdel(&v->p2_name);
	ft_strdel(&v->map_name);
	SDL_DestroyTexture(sv->img);
	SDL_DestroyRenderer(sv->ren);
	SDL_DestroyWindow(sv->win);
	TTF_Quit();
	SDL_Quit();
}

int		main(int argc, char **argv)
{
	t_sdlvar	sv;
	t_v			v;

	set_initial_variables(&sv, &v);
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_CreateWindowAndRenderer(W_W, W_H, 0, &sv.win, &sv.ren);
	sv.img = load_img(sv.ren, "/Users/anel-bou/pro/filler/visualizer/ps.bmp");
	SDL_QueryTexture(sv.img, 0, 0, &sv.pos.w, &sv.pos.h);
	if (read_stable_data(&v) == -1)
	{
		ft_putendl("error: bad player");
		return (0);
	}
	set_map_details(&v);
	while (!sv.quit)
		set_display(&v, &sv);
	liberate_memory(&v, &sv);
	return (0);
}

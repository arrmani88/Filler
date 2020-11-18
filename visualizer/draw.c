/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 03:53:37 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/16 05:54:30 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "SDL_ttf.h"

void		draw_rect(SDL_Renderer *renderer, t_v v)
{
	unsigned int	col;
	int				i;
	int				j;
	int				diff_i;
	int				diff_j;

	set_display_dimensions(&v);
	i = -1;
	diff_i = v.corner_i;
	while (++i < v.dim_ty)
	{
		j = -1;
		diff_j = v.corner_j;
		while (++j < v.dim_tx)
		{
			col = 0x4FFFFFF;
			(ft_toupper(v.tab[i][j]) == 'O') ? col = 0xFF9D9F00 : 0;
			(ft_toupper(v.tab[i][j]) == 'X') ? col = 0xffc8ffe6 : 0;
			roundedBoxColor(renderer, (i + diff_i), (j + diff_j),
			(i + diff_i + v.rec_surf), (j + diff_j + v.rec_surf), v.angle, col);
			diff_j += v.diff_j;
		}
		diff_i += v.diff_i;
	}
}

SDL_Texture	*load_img(SDL_Renderer *renderer, const char *file_name)
{
	SDL_Surface	*img;
	SDL_Texture	*texture;

	if (!(img = SDL_LoadBMP(file_name)))
	{
		puts("Loading image faillure");
		exit(EXIT_FAILURE);
	}
	if (!(texture = SDL_CreateTextureFromSurface(renderer, img)))
	{
		fprintf(stderr, "Error SDL_CreateTextureFromSurface %s",
				SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(img);
	return (texture);
}

void		draw_image(SDL_Renderer *renderer, SDL_Texture *img, SDL_Rect pos)
{
	SDL_Rect dest;

	dest = (SDL_Rect){pos.x, pos.y, pos.w, pos.h};
	SDL_RenderCopy(renderer, img, NULL, &dest);
}

void		wrt(SDL_Renderer *ren, char *txt, int pt_y, SDL_Color col)
{
	SDL_Rect	message_rect;
	TTF_Font	*sans;
	SDL_Surface	*surfacemessage;
	SDL_Texture	*message;
	int			name_sz;

	name_sz = ft_strlen(txt);
	sans = NULL;
	sans = TTF_OpenFont("visualizer/a.otf", 400);
	surfacemessage = TTF_RenderText_Solid(sans, txt, col);
	message = SDL_CreateTextureFromSurface(ren, surfacemessage);
	message_rect.x = 1300;
	message_rect.y = pt_y;
	message_rect.w = name_sz * 45;
	message_rect.h = 100;
	if (pt_y == 350)
	{
		message_rect.w = 200;
		message_rect.h = 40;
	}
	TTF_CloseFont(sans);
	SDL_FreeSurface(surfacemessage);
	SDL_RenderCopy(ren, message, NULL, &message_rect);
	SDL_DestroyTexture(message);
}

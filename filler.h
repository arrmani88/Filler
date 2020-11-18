/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:10:36 by anel-bou          #+#    #+#             */
/*   Updated: 2019/12/16 04:07:43 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include </Users/anel-bou/.brew/Cellar/sdl2/2.0.10/include/SDL2/SDL.h>

typedef struct		s_p
{
	int				x;
	int				y;
}					t_p;

typedef struct		s_v
{
	int				*coor;
	int				c;
	int				**tab;
	int				dim_tx;
	int				dim_ty;
	int				dim_px;
	int				dim_py;
	int				headx;
	int				heady;
	int				sum;
	char			ply;
	int				right_move;
	int				height_move;
	int				left_move;
	int				lowering_move;
	char			*p1_name;
	char			*p2_name;
	int				p1sc;
	int				p2sc;
	int				angle;
	int				rec_surf;
	int				diff_i;
	int				diff_j;
	int				corner_i;
	int				corner_j;
	char			*map_name;
	int				i;
	t_p				p;
}					t_v;

typedef struct		s_sdlvar
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*img;
	SDL_Color		lightb;
	SDL_Color		y;
	SDL_Color		gr;
	SDL_Rect		pos;
	SDL_bool		quit;
}					t_sdlvar;

void				set_display_dimensions(t_v *v);
void				set_map_details(t_v *v);
void				set_display(t_v *v, t_sdlvar *sv);
void				set_initial_variables(t_sdlvar *sv, t_v *v);
void				draw_rect(SDL_Renderer *renderer, t_v v);
SDL_Texture			*load_img(SDL_Renderer *renderer, const char *file_name);
void				draw_image(SDL_Renderer *renderer, SDL_Texture *img,
					SDL_Rect pos);
void				wrt(SDL_Renderer *ren, char *txt, int pt_y, SDL_Color col);
int					update_input(void);
int					filler(t_v *v, int count);
int					read_data();
int					read_variable_data(t_v *v, int count);
int					read_stable_data(t_v *v);
void				set_lowering_map(t_v *v);
void				set_left_map(t_v *v);
void				set_right_map(t_v *v);
void				set_height_map(t_v *v);
void				print_map(t_v v);
int					read_map();
void				heat_map(t_v *v);
int					set_layer(t_v *v, int layern);
void				get_piece_coor(t_v *v);
int					check_low_side(t_v v);
int					check_high_side(t_v v);
int					check_right_side(t_v *v);
int					check_left_side(t_v *v);
int					check_point(t_v *v, int x, int y);
int					check_pp(t_v *v);
void				check_lowering_level(t_v *v);
void				check_left_level(t_v *v);
void				check_right_level(t_v *v);
void				check_height_level(t_v *v);

#endif

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/10 23:17:22 by anel-bou          #+#    #+#              #
#    Updated: 2019/12/20 16:55:36 by anel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = main.o\
		heat_map.o\
		check_sides.o\
		get_point_coor.o\
		get_direction.o\
		set_maps.o\
		filler.o\
		visualizer/fill_variables.o\
		visualizer/draw.o\
		visualizer/visualizer.o\
		visualizer/read_stable_data.o\
		visualizer/read_variable_data.o\
		gnl/get_next_line.o\
		libft/ft_strcount.o\
		libft/ft_abs.o\
		libft/ft_atoi.o\
		libft/ft_bzero.o\
		libft/ft_clettercount.o\
		libft/ft_cwordcount.o\
		libft/ft_decilen.o\
		libft/ft_del_char.o\
		libft/ft_isalnum.o\
		libft/ft_isalpha.o\
		libft/ft_isascii.o\
		libft/ft_isdigit.o\
		libft/ft_islower.o\
		libft/ft_isprint.o\
		libft/ft_isupper.o\
		libft/ft_iswhitespace.o\
		libft/ft_itoa.o\
		libft/ft_lst_nb_chr.o\
		libft/ft_lst_nb_chr_n_add.o\
		libft/ft_lstadd.o\
		libft/ft_lstadd_end.o\
		libft/ft_lstdel.o\
		libft/ft_lstdelone.o\
		libft/ft_lstiter.o\
		libft/ft_lstmap.o\
		libft/ft_lstnew.o\
		libft/ft_lstsize.o\
		libft/ft_memalloc.o\
		libft/ft_memccpy.o\
		libft/ft_memchr.o\
		libft/ft_memcmp.o\
		libft/ft_memcpy.o\
		libft/ft_memdel.o\
		libft/ft_memmove.o\
		libft/ft_memset.o\
		libft/ft_printstr2.o\
		libft/ft_putchar.o\
		libft/ft_putchar_fd.o\
		libft/ft_putcol.o\
		libft/ft_putendl.o\
		libft/ft_putendl_fd.o\
		libft/ft_putnbr.o\
		libft/ft_putnbr_fd.o\
		libft/ft_putnchar.o\
		libft/ft_putnchar_fd.o\
		libft/ft_putnstr.o\
		libft/ft_putnstr_fd.o\
		libft/ft_putstr.o\
		libft/ft_putstr_fd.o\
		libft/ft_sort_int_tab.o\
		libft/ft_stralloc.o\
		libft/ft_strcat.o\
		libft/ft_strchr.o\
		libft/ft_strclr.o\
		libft/ft_strcmp.o\
		libft/ft_strcpy.o\
		libft/ft_strdel.o\
		libft/ft_strdup.o\
		libft/ft_strequ.o\
		libft/ft_striter.o\
		libft/ft_striteri.o\
		libft/ft_strjoin.o\
		libft/ft_strlcat.o\
		libft/ft_strlen.o\
		libft/ft_strmap.o\
		libft/ft_strmapi.o\
		libft/ft_strncat.o\
		libft/ft_strncmp.o\
		libft/ft_strncpy.o\
		libft/ft_strnequ.o\
		libft/ft_strnew.o\
		libft/ft_strnjoin.o\
		libft/ft_strnstr.o\
		libft/ft_strrchr.o\
		libft/ft_strsplit.o\
		libft/ft_strstock.o\
		libft/ft_strstr.o\
		libft/ft_strsub.o\
		libft/ft_strtrim.o\
		libft/ft_table2_len.o\
		libft/ft_table3_len.o\
		libft/ft_tolower.o\
		libft/ft_toupper.o\
		ft_printf/biggest_n.o\
		ft_printf/ft_printf.o\
		ft_printf/get_arg_format.o\
		ft_printf/incr.o\
		ft_printf/inval.o\
		ft_printf/my_decilen.o\
		ft_printf/my_putnbr.o\
		ft_printf/print_base.o\
		ft_printf/print_c.o\
		ft_printf/print_d.o\
		ft_printf/print_s.o\
		ft_printf/print_u.o\
		ft_printf/set_for_p.o\
		ft_printf/set_t_arg.o\
		ft_printf/pf_conv.o\
		ft_printf/float/add.o\
		ft_printf/float/calculate_float.o\
		ft_printf/float/mult.o\
		ft_printf/float/pow.o\
		ft_printf/float/print_fl.o\
		ft_printf/float/rounding.o\

INC = -I /Users/anel-bou/.brew/Cellar/sdl2_gfx/1.0.4/include/SDL2 -I /Users/anel-bou/.brew/Cellar/sdl2/2.0.10/include/SDL2

SDL = -I/Users/anel-bou/.brew/include/SDL2 -D_THREAD_SAFE -L/Users/anel-bou/.brew/lib -lSDL2

NAME = filler.a

all: $(NAME)

$(NAME): $(OBJ) 
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	gcc main.c filler.a -o anel-bou.filler
	gcc visualizer/visualizer.c filler.a $(SDL) /Users/anel-bou/.brew/Cellar/sdl2_gfx/1.0.4/lib/libSDL2_gfx.a -lSDL2_ttf -o vzl

%.o : %.c
	gcc -g $(INC) -c $< -o $@

clean:
	
	rm -f $(OBJ)
	rm -f gnl/*.o
	make -C libft/ clean
	make -C ft_printf/ clean

fclean: clean
	rm -rf vzl
	rm -rf anel-bou.filler
	rm -f $(NAME)
	make -C libft/ fclean
	make -C ft_printf/ fclean

re: fclean all

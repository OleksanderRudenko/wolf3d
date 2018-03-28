/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:57:23 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/20 16:35:20 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

int		main(int argc, char **argv)
{
	t_sdl_manange	wolf;
	int				a;

	wolf.begin = read_file(argv[1]);
	constructor_lego(&wolf);
	check_valid_map(&wolf);
	check_valid_map2(&wolf);
	check_valid_map3(&wolf);
	a = menu(&wolf);
	while (a == 1)
	{
		if (!poll_event(&wolf))
			return (0);
		ft_bzero(wolf.win_surface->pixels, WIDTH * HEIGHT * 4);
		maluy_stinu(&wolf);
		draw_sight(&wolf);
		SDL_BlitScaled(wolf.status_line, NULL,
				wolf.win_surface, &wolf.line_rect);
		draw_sprite(&wolf.guns[wolf.active_gun], &wolf);
		show_face(&wolf.face, &wolf);
		print_text_on_screen(&wolf, wolf.text.bullet_left);
		SDL_UpdateWindowSurface(wolf.win);
	}
	destructor_lego(&wolf);
	return (0);
}

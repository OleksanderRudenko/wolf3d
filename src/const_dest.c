/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_dest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:17:37 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/28 13:46:05 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

void	constructor_lego(t_sdl_manange *s)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_putendl(SDL_GetError());
	if (TTF_Init() < 0)
		ft_putendl(TTF_GetError());
	if (IMG_Init(IMG_INIT_PNG) < 0)
		ft_putendl(IMG_GetError());
	s->win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT + 100, SDL_WINDOW_OPENGL);
	init_text(s);
	init_values(s);
	load_music(s);
	load_weapon(s);
	load_face(s);
}

void	destructor_lego(t_sdl_manange *s)
{
	del_music(s);
	pochistu_vse(s);
}

int		loll(t_sdl_manange *s)
{
	if (s->x >= s->im[0].x && s->x <= s->im[0].x + s->im[0].w &&
		s->y >= s->im[0].y && s->y <= s->im[0].y + s->im[0].h)
		return (1);
	return (0);
}

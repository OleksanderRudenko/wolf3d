/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:50:05 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/12 16:33:23 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

static void	bl_menu(t_sdl_manange *s)
{
	SDL_BlitScaled(s->menus[4], NULL, s->win_surface, NULL);
	SDL_BlitScaled(s->menus[0], NULL, s->win_surface, &s->im[0]);
	SDL_BlitScaled(s->menus[1], NULL, s->win_surface, &s->im[1]);
}

int			menu(t_sdl_manange *s)
{
	init_menu(s);
	while (1)
	{
		bl_menu(s);
		while (SDL_PollEvent(&s->ev))
		{
			s->x = s->ev.button.x;
			s->y = s->ev.button.y;
			if (s->ev.type == SDL_QUIT || (s->ev.type == SDL_KEYDOWN &&
				s->ev.key.keysym.sym == SDLK_ESCAPE))
				return (del_surf_inmenu(s, 5, 0));
			else if (s->ev.type == SDL_MOUSEBUTTONDOWN)
			{
				if (loll(s))
					return (del_surf_inmenu(s, 5, 1));
				if (s->x >= s->im[1].x && s->x <= s->im[1].x + s->im[1].w &&
					s->y >= s->im[1].y && s->y <= s->im[1].y + s->im[1].h)
					return (del_surf_inmenu(s, 5, 0));
			}
			else if (s->ev.type == SDL_MOUSEMOTION)
				if_mouse_motion_menu(s, s->x, s->y);
			SDL_UpdateWindowSurface(s->win);
		}
	}
	return (del_surf_inmenu(s, 5, 1));
}

void		if_mouse_motion_menu(t_sdl_manange *s, int x, int y)
{
	if (x >= s->im[0].x && x <= s->im[0].x + s->im[0].w &&
		y >= s->im[0].y && y <= s->im[0].y + s->im[0].h)
		SDL_BlitScaled(s->menus[2], NULL, s->win_surface, &s->im[0]);
	if (x >= s->im[1].x && x <= s->im[1].x + s->im[1].w &&
		y >= s->im[1].y && y <= s->im[1].y + s->im[1].h)
		SDL_BlitScaled(s->menus[3], NULL, s->win_surface, &s->im[1]);
}

void		init_menu(t_sdl_manange *s)
{
	s->menus = (SDL_Surface **)malloc(sizeof(SDL_Surface*) * 5);
	s->menus[0] = load_image("pic/Play.png");
	s->menus[1] = load_image("pic/Quit.png");
	s->menus[2] = load_image("pic/Play2.png");
	s->menus[3] = load_image("pic/Quit2.png");
	s->menus[4] = load_image("pic/fon.png");
	s->im[0].x = 400;
	s->im[0].y = 300;
	s->im[0].w = 250;
	s->im[0].h = 100;
	s->im[1].x = 400;
	s->im[1].y = 500;
	s->im[1].w = 250;
	s->im[1].h = 100;
}

int			del_surf_inmenu(t_sdl_manange *s, int num, int flag)
{
	int	i;

	i = -1;
	while (++i < num)
		SDL_FreeSurface(s->menus[i]);
	return (flag);
}

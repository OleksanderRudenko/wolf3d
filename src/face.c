/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:53:59 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/28 13:41:10 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

void	load_face(t_sdl_manange *s)
{
	init_sprite(&s->face, "pic/face", 4);
	s->face.frametime_faces = 1;
	s->face.sn_face = 0;
	s->face_rect.x = WIDTH / 2 - 80;
	s->face_rect.y = HEIGHT + 10;
	s->face_rect.h = 85;
	s->face_rect.w = 75;
	s->face.fps_face = 200;
}

void	show_face(t_sprite *s, t_sdl_manange *m)
{
	if (s->fps_face / s->frametime_faces == 1)
	{
		s->frametime_faces = 1;
		s->sn_face++;
		if (s->sn_face >= 4)
		{
			s->sn_face = 0;
		}
	}
	s->frametime_faces++;
	SDL_BlitScaled(s->frames[s->sn_face], NULL, m->win_surface, &m->face_rect);
}

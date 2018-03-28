/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:19:43 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/28 12:41:18 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

void	sprite_line(t_sdl_manange *s, int x)
{
	t_obj	o;
	int		texy;
	int		y;
	int		n;

	n = 0;
	init_for_sprite(s, &o, &n);
	o.texture_x = (int)(256 * (s->map->x - (-fabs((HEIGHT / (o.tr_y))) / 2 +
	(int)((s->win_surface->w / 2) * (1 + o.tr_x / o.tr_y)))) *
	s->im_surf[n]->w / fabs((HEIGHT / (o.tr_y)))) / 256;
	y = o.start_y - 1;
	s->map->buffer = (unsigned int *)s->win_surface->pixels +
	o.start_y * WIDTH + x;
	while (++y < o.start_x)
	{
		texy = !o.sprt_h ? 0 : (((y * 2 - HEIGHT + o.sprt_h) *
		s->im_surf[n]->h) / o.sprt_h) / 2;
		if (!*s->map->buffer && o.texture_x >= 0 && texy >= 0 &&
			o.texture_x < s->im_surf[n]->w && texy < s->im_surf[n]->w)
			*s->map->buffer = ((unsigned int*)s->im_surf[n]->pixels)
				[s->im_surf[n]->w * texy + o.texture_x] & 0xFFFFFF;
		s->map->buffer += WIDTH;
	}
}

void	init_for_sprite(t_sdl_manange *s, t_obj *o, int *n)
{
	*n = s->floor[s->map->m_x][s->map->m_y];// == 7 ? 7 : 8;
	o->sp_x = s->map->m_x + 0.5 - s->map->ppos_x;
	o->sp_y = s->map->m_y + 0.5 - s->map->ppos_y;
	o->inv_det = 1.0 / (s->map->plane_x * s->map->dir_y -
			s->map->dir_x * s->map->plane_y);
	o->tr_x = o->inv_det * (s->map->dir_y * o->sp_x - s->map->dir_x * o->sp_y);
	o->tr_y = o->inv_det * (-s->map->plane_y * o->sp_x +
			s->map->plane_x * o->sp_y);
	o->sprt_h = fabs(HEIGHT / (o->tr_y));
	o->start_y = -o->sprt_h / 2 + HEIGHT / 2;
	o->start_x = o->sprt_h / 2 + HEIGHT / 2;
	o->start_x = o->start_x >= HEIGHT ? HEIGHT - 1 : o->start_x;
	o->start_y = o->start_y < 0 ? 0 : o->start_y;
}

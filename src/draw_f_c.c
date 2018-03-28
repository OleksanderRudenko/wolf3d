/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_f_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:50:16 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/12 16:48:00 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

void	maluy_pidlogu_ta_stelu(t_sdl_manange *s)
{
	int	y;

	init_floor_c(s);
	s->map->dist_wall = s->map->pwd;
	if (s->map->dr_e < 0)
		s->map->dr_e = HEIGHT;
	y = s->map->dr_e;
	while (y < HEIGHT)
	{
		s->map->curr_dist = HEIGHT / (2.0 * y - HEIGHT);
		s->map->weight = (s->map->curr_dist) / (s->map->dist_wall);
		s->map->fl_tx = (int)((s->map->weight * s->map->fl_xwall +
			(1.0 - s->map->weight) * s->map->ppos_x) * 64) % 64;
		s->map->fl_ty = (int)((s->map->weight * s->map->fl_ywall +
			(1.0 - s->map->weight) * s->map->ppos_y) * 64) % 64;
		if (!*s->map->buffer)
			*s->map->buffer = ((unsigned int *)s->im_surf[5]->pixels)
		[64 * s->map->fl_ty + s->map->fl_tx];
		if (!*(s->map->buffer + (HEIGHT - 2 * y) * WIDTH))
			*(s->map->buffer + (HEIGHT - 2 * y) * WIDTH) = ((unsigned int *)
				s->im_surf[6]->pixels)[64 * s->map->fl_ty + s->map->fl_tx];
		s->map->buffer += WIDTH;
		y++;
	}
}

void	init_floor_c(t_sdl_manange *s)
{
	if (s->map->side == 0 && s->map->rd_x > 0)
	{
		s->map->fl_xwall = s->map->m_x;
		s->map->fl_ywall = s->map->m_y + s->map->w_x;
	}
	else if (s->map->side == 0 && s->map->rd_x < 0)
	{
		s->map->fl_xwall = s->map->m_x + 1.0;
		s->map->fl_ywall = s->map->m_y + s->map->w_x;
	}
	else if (s->map->side == 1 && s->map->rd_y > 0)
	{
		s->map->fl_xwall = s->map->m_x + s->map->w_x;
		s->map->fl_ywall = s->map->m_y;
	}
	else
	{
		s->map->fl_xwall = s->map->m_x + s->map->w_x;
		s->map->fl_ywall = s->map->m_y + 1.0;
	}
}

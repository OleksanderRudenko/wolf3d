/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:56:26 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/28 13:06:20 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

void	maluy_stinu(t_sdl_manange *s)
{
	s->map->x = -1;
	while (++s->map->x < WIDTH)
	{
		init_for_wall(s);
		init_for_wall2(s);
		was_hit(s);
		xd(s);
		davay_textyry(s);
		init_for_wall3(s);
		while (++s->map->y < s->map->dr_e)
		{
			s->map->d = s->map->y * 2 - HEIGHT + s->map->l_h;
			s->map->t_y = ((s->map->d * s->im_surf[s->map->n]->w /
				s->map->l_h) / 2);
			if (!*s->map->buffer)
				*s->map->buffer = ((unsigned int *)
					s->im_surf[s->map->n]->pixels)
			[s->im_surf[s->map->n]->h * s->map->t_y + s->map->t_x];
			s->map->buffer += WIDTH;
		}
		maluy_pidlogu_ta_stelu(s);
	}
}

void	init_for_wall(t_sdl_manange *s)
{
	s->map->ra = 2 * s->map->x / (float)(WIDTH) - 1;
	s->map->rd_x = s->map->dir_x + s->map->plane_x * s->map->ra;
	s->map->rd_y = s->map->dir_y + s->map->plane_y * s->map->ra;
	s->map->m_x = (int)(s->map->ppos_x);
	s->map->m_y = (int)(s->map->ppos_y);
	s->map->dd_x = fabs(1 / s->map->rd_x);
	s->map->dd_y = fabs(1 / s->map->rd_y);
	s->map->hit = 0;
}

void	init_for_wall2(t_sdl_manange *s)
{
	if (s->map->rd_x < 0)
	{
		s->map->st_x = -1;
		s->map->rlx = (s->map->ppos_x - s->map->m_x) * s->map->dd_x;
	}
	else
	{
		s->map->st_x = 1;
		s->map->rlx = (s->map->m_x + 1.0 - s->map->ppos_x) * s->map->dd_x;
	}
	if (s->map->rd_y < 0)
	{
		s->map->st_y = -1;
		s->map->rly = (s->map->ppos_y - s->map->m_y) * s->map->dd_y;
	}
	else
	{
		s->map->st_y = 1;
		s->map->rly = (s->map->m_y + 1.0 - s->map->ppos_y) * s->map->dd_y;
	}
}

void	was_hit(t_sdl_manange *s)
{
	while (1)
	{
		if (s->map->rlx < s->map->rly)
		{
			s->map->rlx += s->map->dd_x;
			s->map->m_x += s->map->st_x;
			s->map->side = 0;
		}
		else
		{
			s->map->rly += s->map->dd_y;
			s->map->m_y += s->map->st_y;
			s->map->side = 1;
		}
		if (s->map->x == WIDTH / 2 && s->floor[s->map->m_x][s->map->m_y] == 7 &&
			s->shoot == 1)
		{
			s->floor[s->map->m_x][s->map->m_y] = rand() % 2 + 8;
			s->shoot = 0;
		}
		if (s->floor[s->map->m_x][s->map->m_y] > 0 &&
			(is_sprite(s->floor[s->map->m_x][s->map->m_y]) == 0))
			break ;
		(is_sprite(s->floor[s->map->m_x][s->map->m_y])) ? sprite_line(s, s->map->x) : 0;
	}
}

void	init_for_wall3(t_sdl_manange *s)
{
	s->map->t_x = (int)(s->map->w_x * (double)(64));
	if (s->map->side == 0 && s->map->rd_x > 0)
		s->map->t_x = 64 - s->map->t_x - 1;
	if (s->map->side == 1 && s->map->rd_y < 0)
		s->map->t_x = 64 - s->map->t_x - 1;
	s->map->y = s->map->dr_s - 1;
	s->map->buffer = (unsigned int *)s->win_surface->pixels +
		s->map->dr_s * s->win_surface->w + s->map->x;
}

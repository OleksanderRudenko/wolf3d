/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_inites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:08:50 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/28 13:19:58 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

void	xd(t_sdl_manange *s)
{
	if (s->map->side == 0)
		s->map->pwd = (s->map->m_x - s->map->ppos_x +
			(1 - s->map->st_x) / 2) / s->map->rd_x;
	else
		s->map->pwd = (s->map->m_y - s->map->ppos_y +
			(1 - s->map->st_y) / 2) / s->map->rd_y;
	s->map->l_h = (int)(HEIGHT / s->map->pwd);
	s->map->dr_s = -s->map->l_h / 2 + HEIGHT / 2;
	if (s->map->dr_s < 0)
		s->map->dr_s = 0;
	s->map->dr_e = s->map->l_h / 2 + HEIGHT / 2;
	if (s->map->dr_e >= HEIGHT)
		s->map->dr_e = HEIGHT - 1;
}

void	davay_textyry(t_sdl_manange *s)
{
    s->map->n = is_wall(s->floor[s->map->m_x][s->map->m_y]);
	if (s->map->side == 0)
		s->map->w_x = s->map->ppos_y + s->map->pwd * s->map->rd_y;
	else
		s->map->w_x = s->map->ppos_x + s->map->pwd * s->map->rd_x;
	s->map->w_x -= floor(s->map->w_x);
}

void	ololo(t_sdl_manange *s)
{
	s->map->ppos_x += 0.5;
	s->map->ppos_y += 0.5;
	s->map->dir_x = -1;
	s->map->dir_y = 0;
	s->map->plane_x = 0;
	s->map->plane_y = 0.66;
	s->map->mv_speed = 0.3f;
	s->map->rot_speed = 0.05f;
	s->map->hit = 0;
	s->map->n = 0;
	s->num = 0;
	s->active_gun = 0;
	s->shoot = 0;
}

int		is_wall(int n)
{
	int arr[] = {1,2,3,4,5};
	int i = 0;

	while (i < 5)
	{
		if (arr[i] == n)
			return (arr[i]);
		++i;
	}
	return (0);
}

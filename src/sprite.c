/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:50:05 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/28 14:18:29 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

void	draw_sprite(t_sprite *s, t_sdl_manange *m)
{
	if (s->fps / s->frametime == 4)
	{
		s->frametime = 1;
		s->sn++;
		if (s->sn >= s->numframes)
		{
			if (m->active_gun == 2 || m->active_gun == 3)
				m->active_gun = m->current_gun;
			s->sn = 0;
			if (!s->loop)
				s->active = 0;
		}
	}
	s->frametime += s->active;
	SDL_BlitScaled(s->frames[s->sn], NULL, m->win_surface, &s->rect);
}

void	init_sprite(t_sprite *s, char *file, int num)
{
	int		i;
	char	*buf;
	char	*tmp;

	i = 0;
	s->fps = 24;
	s->frametime = 1;
	s->sn = 0;
	s->loop = 0;
	s->active = 0;
	s->numframes = num;
	s->frames = (SDL_Surface **)malloc(num * sizeof(SDL_Surface *));
	buf = ft_strnew(100);
	while (i < num)
	{
		ft_strcpy(buf, file);
		tmp = (ft_itoa(i));
		ft_strcat(buf, tmp);
		ft_strcat(buf, ".png");
		ft_strdel(&tmp);
		s->frames[i] = load_image(buf);
		i++;
		ft_bzero(buf, 100);
	}
	ft_strdel(&buf);
}

void	delete_sprite(t_sprite *s)
{
	int		i;

	i = 0;
	while (i < s->numframes)
	{
		SDL_FreeSurface(s->frames[i]);
		i++;
	}
}

int	is_sprite(int n)
{
	int	arr[] = {7,8,9};
	int	i = 0;

	while (i < 3)
	{
		if (n == arr[i])
			return (1);
		++i;
	}
	return (0);
}

int	is_move(int n)
{
	int	arr[] = {8,9};
	int	i = 0;

	while (i < 2)
	{
		if (n == arr[i])
			return (1);
		++i;
	}
	return (0);
}

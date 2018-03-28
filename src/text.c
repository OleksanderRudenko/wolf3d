/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:02:41 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/12 19:25:53 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

void	init_text(t_sdl_manange *s)
{
	s->text.text_color.r = 255;
	s->text.text_color.g = 255;
	s->text.text_color.b = 0;
	s->text.bullet_left = 2;
	s->text.font = TTF_OpenFont("Roboto-Black.ttf", 32);
	if (s->text.font == NULL)
	{
		ft_putendl("font is shit");
		exit(-1);
	}
	s->text.text_rect.x = WIDTH - 400;
	s->text.text_rect.y = HEIGHT + 30;
	s->text.text_rect.w = 50;
	s->text.text_rect.h = 50;
}

void	print_text_on_screen(t_sdl_manange *s, int text)
{
	char *str;

	str = ft_itoa(text);
	s->text.mesaga = TTF_RenderUTF8_Blended(s->text.font,
		str, s->text.text_color);
	ft_strdel(&str);
	SDL_BlitScaled(s->text.mesaga, NULL, s->win_surface, &s->text.text_rect);
	SDL_FreeSurface(s->text.mesaga);
	s->text.mesaga = NULL;
}

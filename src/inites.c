/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inites.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:53:22 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/28 14:31:41 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woof.h"

void	init_values(t_sdl_manange *s)
{
	char	**pos;

	count_symbols(s->begin);
	s->floor = init_floor(s);
	load_textures(s);
	s->win_surface = SDL_GetWindowSurface(s->win);
	if (ft_num_words(s->begin->param, ' ') != 2)
		bad_position();
	pos = ft_strsplit(s->begin->param, ' ');
	s->map = (t_wolf *)malloc(sizeof(t_wolf));
	if ((s->map->ppos_x = (float)ft_atoi(pos[0])) <= 0)
		bad_position();
	if ((s->map->ppos_y = (float)ft_atoi(pos[1])) <= 0)
		bad_position();
	if ((int)s->map->ppos_x >= s->begin->vert)
		bad_position();
	if ((int)s->map->ppos_y >= s->begin->hor)
		bad_position();
	if (s->floor[(int)s->map->ppos_x][(int)s->map->ppos_y])
		bad_position();
	ololo(s);
	free_double(pos);
}

void	load_music(t_sdl_manange *s)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		ft_putendl(Mix_GetError());
	s->sound.chunks[0] = Mix_LoadWAV("music/Chain.mp3");
	if (s->sound.chunks[0] == NULL)
		ft_putendl(Mix_GetError());
	s->sound.chunks[1] = Mix_LoadWAV("music/Shotgun.mp3");
	if (s->sound.chunks[1] == NULL)
		ft_putendl(Mix_GetError());
	s->sound.chunks[2] = Mix_LoadWAV("music/Fuck1.wav");
	if (s->sound.chunks[2] == NULL)
		ft_putendl(Mix_GetError());
	s->sound.chunks[3] = Mix_LoadWAV("music/Fuck2.wav");
	if (s->sound.chunks[3] == NULL)
		ft_putendl(Mix_GetError());
	s->sound.chunks[4] = Mix_LoadWAV("music/Fuck3.wav");
	if (s->sound.chunks[4] == NULL)
		ft_putendl(Mix_GetError());
	s->sound.back = Mix_LoadMUS("music/HBT.mp3");
	if (s->sound.back == NULL)
		ft_putendl(Mix_GetError());
	Mix_PlayMusic(s->sound.back, -1);
	Mix_VolumeMusic(5);
}

void	load_textures(t_sdl_manange *s)
{
	if (!(s->im_surf = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 10)))
		mal_er();
	s->im_surf[0] = load_image("pic/bluestone.bmp");
	s->im_surf[1] = load_image("pic/pw.bmp");
	s->im_surf[2] = load_image("pic/st.bmp");
	s->im_surf[3] = load_image("pic/cs.bmp");
	s->im_surf[4] = load_image("pic/mossy.bmp");
	s->im_surf[5] = load_image("pic/gs.bmp");
	s->im_surf[6] = load_image("pic/ceil.bmp");
	s->im_surf[7] = load_image("pic/barrel.png");
	s->im_surf[8] = load_image("pic/b_barrel.png");
	s->im_surf[9] = load_image("pic/b_barrel2.png");
}

void	load_weapon(t_sdl_manange *s)
{
	s->status_line = load_image("pic/line.png");
	s->line_rect.x = 0;
	s->line_rect.y = HEIGHT;
	s->line_rect.h = 100;
	s->line_rect.w = WIDTH;

	s->guns = (t_sprite *)malloc(sizeof(t_sprite) * NUM_GUNS);
	init_sprite(&s->guns[0], "pic/chain", 2);
	s->guns[0].rect.x = WIDTH / 2 - 75;
	s->guns[0].rect.y = HEIGHT - 250;
	s->guns[0].rect.h = 250;
	s->guns[0].rect.w = 250;

	init_sprite(&s->guns[1], "pic/s", 6);
	s->guns[1].rect.x = WIDTH / 2 - 100;
	s->guns[1].rect.y = HEIGHT - 200;
	s->guns[1].rect.h = 200;
	s->guns[1].rect.w = 200;

	init_sprite(&s->guns[2], "pic/r", 4);
	s->guns[2].rect.x = WIDTH / 2 - 100;
	s->guns[2].rect.y = HEIGHT - 200;
	s->guns[2].rect.h = 200;
	s->guns[2].rect.w = 300;

	init_sprite(&s->guns[3], "pic/f", 4);
	s->guns[3].rect.x = WIDTH / 2 - 100;
	s->guns[3].rect.y = HEIGHT - 300;
	s->guns[3].rect.h = 300;
	s->guns[3].rect.w = 300;

	s->active_gun = 0;
	s->current_gun = s->active_gun;
}

void	draw_sight(t_sdl_manange *s)
{
	int i;

	i = -15;
	s->map->sight = (unsigned int *)s->win_surface->pixels;
	while (i < 15)
	{
		s->map->sight[HEIGHT * WIDTH / 2 + WIDTH / 2 + i] = 0xff0000;
		s->map->sight[HEIGHT * WIDTH / 2 + (i * WIDTH + WIDTH / 2)] = 0xff0000;
		i++;
	}
}

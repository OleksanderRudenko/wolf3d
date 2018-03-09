#include "woof.h"

void	del_music(t_sdl_manange *s)
{
	int i;

	i = 0;
	while (i < 2)
	{
		Mix_FreeChunk(s->sound.chunks[i]);
		s->sound.chunks[i++] = NULL;
	}
}

void	pochistu_vse(t_sdl_manange *s)
{
	int i;

	i = 0;
	free(s->map);
	SDL_FreeSurface(s->win_surface);
	s->win_surface = NULL;
	while (i < 8)
	{
		SDL_FreeSurface(s->im_surf[i]);
		s->im_surf[i++] = NULL;
	}
	delete_sprite(&s->guns[0]);
	delete_sprite(&s->guns[1]);
	delete_sprite(&s->guns[2]);
	SDL_FreeSurface(s->status_line);
	s->status_line = NULL;
	SDL_DestroyWindow(s->win);
	s->win = NULL;
	IMG_Quit();
  	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}

void	free_double(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_strdel(&s[i]);
		i++;
	}
	free(s);
	s = NULL;
}
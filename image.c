#include "woof.h"

SDL_Surface *load_surf(char *filepath)
{
	SDL_Surface * surf;
	surf  = SDL_LoadBMP(filepath);
	if (surf == NULL)
		ft_putendl(SDL_GetError());
	return (surf);
}

#include "woof.h"

SDL_Surface	*load_image(char *filepath)
{
	SDL_Surface * surf;
	surf  = IMG_Load(filepath);
	if (surf == NULL)
	{
		ft_putendl(IMG_GetError());
		exit(0);
	}
	return (surf);
}

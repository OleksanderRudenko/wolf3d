#include "woof.h"

void    constructor_lego(t_sdl_manange *s)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        ft_putendl(SDL_GetError());
    if (TTF_Init() < 0)
        ft_putendl(TTF_GetError());
    if (IMG_Init(IMG_INIT_PNG) < 0)
        ft_putendl(IMG_GetError());
    init_values(s);
    load_music(s);
    load_weapon(s);
    load_face(s);
}

void    destructor_lego(t_sdl_manange *s)
{
    del_music(s);
    pochistu_vse(s);
}
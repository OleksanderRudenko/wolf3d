#include "woof.h"

int menu(t_sdl_manange *s)
{
    int     x;
    int     y;

    init_menu(s);
    SDL_Event   ev;
    while (1)
    {
        SDL_BlitScaled(s->menus[4], NULL, s->win_surface, NULL);
        SDL_BlitScaled(s->menus[0], NULL, s->win_surface, &s->im[0]);
        SDL_BlitScaled(s->menus[1], NULL, s->win_surface, &s->im[1]);
        while (SDL_PollEvent(&ev))
        {
            x = ev.button.x;
            y = ev.button.y;
            if (ev.type == SDL_QUIT || (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_ESCAPE))
            {
                del_surf_inmenu(s,5);
                return 0;
            }
            else if (ev.type == SDL_MOUSEBUTTONDOWN)
            {
                if (x >= s->im[0].x && x<= s->im[0].x + s->im[0].w && y >= s->im[0].y && y<= s->im[0].y + s->im[0].h)
                {
                    del_surf_inmenu(s,5);
                    return (1);
                }
                if (x >= s->im[1].x && x<= s->im[1].x + s->im[1].w && y >= s->im[1].y && y<= s->im[1].y + s->im[1].h)
                {
                    del_surf_inmenu(s,5);
                    return (0);
                }
            }
            else if (ev.type == SDL_MOUSEMOTION)
            {
                if (x >= s->im[0].x && x<= s->im[0].x + s->im[0].w && y >= s->im[0].y && y<= s->im[0].y + s->im[0].h)
                    SDL_BlitScaled(s->menus[2], NULL, s->win_surface, &s->im[0]);
                if (x >= s->im[1].x && x<= s->im[1].x + s->im[1].w && y >= s->im[1].y && y<= s->im[1].y + s->im[1].h)
                    SDL_BlitScaled(s->menus[3], NULL, s->win_surface, &s->im[1]);
            }
            SDL_UpdateWindowSurface(s->win);
        }
    }
    del_surf_inmenu(s,5);
    return (1);
}

void    init_menu(t_sdl_manange *s)
{
    s->menus = (SDL_Surface **)malloc(sizeof(SDL_Surface*) * 5);
    s->menus[0] = load_image("pic/Play.png");
    s->menus[1] = load_image("pic/Quit.png");
    s->menus[2] = load_image("pic/Play2.png");
    s->menus[3] = load_image("pic/Quit2.png");
    s->menus[4] = load_image("pic/fon.png");
    s->im[0].x = 400;
    s->im[0].y = 300;
    s->im[0].w = 250;
    s->im[0].h = 100;
    s->im[1].x = 400;
    s->im[1].y = 500;
    s->im[1].w = 250;
    s->im[1].h = 100;
}

void    del_surf_inmenu(t_sdl_manange *s, int num)
{
    int i;

    i = -1;
    while (++i < num)
        SDL_FreeSurface(s->menus[i]);
}

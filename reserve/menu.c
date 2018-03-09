#include "woof.h"

int menu(t_sdl_manange *s)
{
    Uint32 time;
    int     x;
    int     y;
    const int num_menu = 2;

    SDL_Surface *menus[num_menu];
    SDL_Rect    im[num_menu];
    SDL_Event   ev;

    menus[0] = IMG_Load("pic/lf.png");
    menus[1] = IMG_Load("pic/st.bmp");
    im[0].x = 100;
    im[0].y = 100;
    im[0].w = 50;
    im[0].h = 50;

    im[1].x = 100;
    im[1].y = 200;
    im[1].w = 50;
    im[1].h = 50;
    if (menus[0] == NULL || menus[1] == NULL)
        ft_putendl(IMG_GetError());
    int isdone = 1;
    while (isdone == 1)
    {
        SDL_BlitScaled(menus[0], NULL, s->win_surface, &im[0]);
        SDL_BlitScaled(menus[1], NULL, s->win_surface, &im[1]);
        time = SDL_GetTicks();
        while (SDL_PollEvent(&ev))
        {
            if (ev.type == SDL_QUIT || (ev.type == SDL_KEYDOWN && ev.key.keysym.sym == SDLK_ESCAPE))
            {
                SDL_FreeSurface(menus[0]);
                SDL_FreeSurface(menus[1]);
                return 0;
            }
            else if (ev.type == SDL_MOUSEBUTTONDOWN)
            {
                x = ev.button.x;
                y = ev.button.y;
                if (x >= im[0].x && x<= im[0].x + im[0].w && y >= im[0].y && y<= im[0].y + im[0].h)
                    return (1);
                if (x >= im[1].x && x<= im[1].x + im[1].w && y >= im[1].y && y<= im[1].y + im[1].h)
                    return (0);
                }
                SDL_UpdateWindowSurface(s->win);
            }
        }
        return (1);
}

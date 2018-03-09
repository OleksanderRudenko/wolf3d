#include "woof.h"

void    draw_sprite(t_sprite *s, t_sdl_manange *m)
{
    if (s->fps / s->frametime == 4)
    {
        s->frametime = 1;
        s->sn++;
        if (s->sn >= s->numframes)
        {
            if (m->active_gun == 2)
                m->active_gun = 1;
            s->sn = 0;
            if (!s->loop)
                s->active = 0; 
        }
    }
    s->frametime += s->active;
    SDL_BlitScaled(s->frames[s->sn], NULL, m->win_surface, &s->rect);
}

void    init_sprite(t_sprite *s, char *file, int num)
{
    s->fps = 24;
    s->frametime = 1;
    s->sn = 0;
    s->loop = 0;
    s->active = 0;
    s->numframes = num;
    s->frames  = (SDL_Surface**) malloc(num * sizeof(SDL_Surface *));
    char *buf = ft_strnew(100);
    int i = 0;
    while (i < num)
    {
        ft_strcpy(buf, file);
        char *tmp = (ft_itoa(i));
        ft_strcat(buf,tmp);
        ft_strcat(buf, ".png");
        ft_strdel(&tmp);
        s->frames[i] = load_image(buf);
        i++;
        ft_bzero(buf, 100);
    }
    ft_strdel(&buf);
}

void    delete_sprite(t_sprite *s)
{
    int i;

    i = 0;
    while (i < s->numframes)
    {
        SDL_FreeSurface(s->frames[i]);
        i++;
    }
}
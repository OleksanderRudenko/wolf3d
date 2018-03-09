#include "woof.h"

void    init_text(t_sdl_manange *s)
{
    s->text.text_color.r = 255;
    s->text.text_color.g = 255;
    s->text.text_color.b = 0;
	s->text.bullet_left = 2;
    s->text.font = TTF_OpenFont("Roboto-Black.ttf", 32);
    if (s->text.font == NULL)
        ft_putendl("font is shit");
    s->text.text_rect.x = WIDTH - 200;
    s->text.text_rect.y = HEIGHT;
    s->text.text_rect.w = 50;
    s->text.text_rect.h = 50;
}

void    print_text_on_screen(t_sdl_manange *s, int text)
{
    char *str;

    str = ft_itoa(text);
    s->text.mesaga = TTF_RenderUTF8_Blended(s->text.font, str, s->text.text_color);
    ft_strdel(&str);
    SDL_BlitScaled(s->text.mesaga, NULL, s->win_surface, &s->text.text_rect);
    SDL_FreeSurface(s->text.mesaga);
    s->text.mesaga = NULL;
}
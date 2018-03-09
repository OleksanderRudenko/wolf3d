#include "woof.h"

void idu_vpered(t_sdl_manange *s)
{
    if (s->floor[(int)(s->map->ppos_x + s->map->dir_x * s->map->mv_speed)][(int)(s->map->ppos_y)] == 0)
    {
        s->map->ppos_x += s->map->dir_x * s->map->mv_speed;
    }
    if (s->floor[(int)(s->map->ppos_x)][(int)(s->map->ppos_y + s->map->dir_y * s->map->mv_speed)] == 0)
    {
        s->map->ppos_y += s->map->dir_y * s->map->mv_speed;
    }
}

void idu_nazad(t_sdl_manange *s)
{

    if (s->floor[(int)(s->map->ppos_x - s->map->dir_x * s->map->mv_speed)][(int)(s->map->ppos_y)] == 0)
    {
        s->map->ppos_x -= s->map->dir_x * s->map->mv_speed;
    }
    if (s->floor[(int)(s->map->ppos_x)][(int)(s->map->ppos_y - s->map->dir_y * s->map->mv_speed)] == 0)
    {
        s->map->ppos_y -= s->map->dir_y * s->map->mv_speed;
    }
}

void povernu_napravo(t_sdl_manange *s)
{
    double oldDirX = s->map->dir_x;
    s->map->dir_x = s->map->dir_x * cosf(-s->map->rot_speed) - s->map->dir_y * sinf(-s->map->rot_speed);
    s->map->dir_y = oldDirX * sinf(-s->map->rot_speed) + s->map->dir_y * cosf(-s->map->rot_speed);
    double oldPlaneX = s->map->plane_x;
    s->map->plane_x = s->map->plane_x * cosf(-s->map->rot_speed) - s->map->plane_y * sinf(-s->map->rot_speed);
    s->map->plane_y = oldPlaneX * sinf(-s->map->rot_speed) + s->map->plane_y * cosf(-s->map->rot_speed);
}

void povernu_nalivo(t_sdl_manange *s)
{
    double oldDirX = s->map->dir_x;
    s->map->dir_x = s->map->dir_x * cos(s->map->rot_speed) - s->map->dir_y * sin(s->map->rot_speed);
    s->map->dir_y = oldDirX * sin(s->map->rot_speed) + s->map->dir_y * cos(s->map->rot_speed);
    double oldPlaneX = s->map->plane_x;
    s->map->plane_x = s->map->plane_x * cos(s->map->rot_speed) - s->map->plane_y * sin(s->map->rot_speed);
    s->map->plane_y = oldPlaneX * sin(s->map->rot_speed) + s->map->plane_y * cos(s->map->rot_speed);
}

void  key_down(SDL_Keycode key, t_sdl_manange *s)
{
  if (key == SDLK_w)
  {
    idu_vpered(s);
  }
  if (key == SDLK_s)
  {
    idu_nazad(s);
  }
  if (key == SDLK_d)
  {
    povernu_napravo(s);
  }
  if (key == SDLK_a)
  {
    povernu_nalivo(s);
  }
  if (key == SDLK_1)
  {
    s->active_gun = 0;
  }
  if (key == SDLK_2)
  {
    s->active_gun = 1;
  }
  if (key == SDLK_r && s->active_gun == 1)
  {
    s->text.bullet_left = 2;
    s->active_gun = 2;
    s->guns[s->active_gun].active = 1;
  }
}

void  mouse_event(SDL_Keycode key, t_sdl_manange *s, int is_down)
{
      if (key == SDL_BUTTON_LEFT)
      {
        s->guns[s->active_gun].loop = is_down;
        if (is_down && s->text.bullet_left > 0)
        {
          s->guns[s->active_gun].active = 1;
          if (s->active_gun == 1)
          {
            s->text.bullet_left--;
            Mix_PlayChannel(0, s->sound.chunks[s->active_gun], 0); // shotgun
            s->shoot = 1;
          }
        }
        if (is_down && s->active_gun == 0)
        {
          s->guns[s->active_gun].active = 1;
          Mix_PlayChannel(0, s->sound.chunks[s->active_gun], 0);
        }
        else if (is_down == 0)
          s->shoot = 0;
      }  
}

int   poll_event(t_sdl_manange *s)
{
  SDL_Event e;

  while (SDL_PollEvent(&e))
    if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
      return (0);
    else if (e.type == SDL_KEYDOWN)
      key_down(e.key.keysym.sym, s);
    else if (e.type == SDL_MOUSEMOTION)
    {
       if (e.motion.xrel > 0)
        {
           povernu_napravo(s);
        }
        else
        {
           povernu_nalivo(s);
        }
    }
    else if (e.type == SDL_MOUSEBUTTONDOWN)
      mouse_event(e.button.button, s, 1);
    else if (e.type == SDL_MOUSEBUTTONUP)
      mouse_event(e.button.button, s, 0);
  return (1);
}
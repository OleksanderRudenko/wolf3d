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
  if (key == SDLK_UP)
  {
    idu_vpered(s);
  }
  if (key == SDLK_DOWN)
  {
    idu_nazad(s);
  }
  if (key == SDLK_RIGHT)
  {
    povernu_napravo(s);
  }
  if (key == SDLK_LEFT)
  {
    povernu_nalivo(s);
  }
}

void  mouse_down_event(SDL_Keycode key, t_sdl_manange *s)
{
      if (key == SDL_BUTTON_LEFT)
      {
        Mix_PlayChannel(0, s->sound.chain, 0);
        s->num = 1;
      }
      if (key == SDL_BUTTON_RIGHT)
      {
        ft_putendl("lol");
       // shoot(s);
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
      mouse_down_event(e.button.button, s);
    else if (e.type == SDL_MOUSEBUTTONUP)
      s->num = 0;
  return (1);
}

void  shoot(t_sdl_manange *s)
{
  float shot_dir_x;
  float shot_dir_y;
  float ray_pos_x = s->map->ppos_x;
  float ray_pos_y = s->map->ppos_y;
  int step_x;
  int step_y;
  float side_x;
  float side_y;
  int hit_wall = 0;
  SDL_Surface *fire;
 
  fire =  IMG_Load("pic/lf.png");
  shot_dir_x = s->map->rd_x + s->map->plane_x;
  shot_dir_y = s->map->rd_y + s->map->plane_y;
  //step_x = 1; // or -1 // shot_dir_x < 0 ? -1 : 1 like this
  //step_y = 1;
  if (shot_dir_x < 0)
  {
    step_x = -1;
    side_x = (ray_pos_x - s->map->m_x) * fabs(1 / s->map->rd_x);
  }
  else
  {
    step_x = 1;
    side_x = (s->map->m_x + 1.0 - ray_pos_x) * fabs(1 / s->map->rd_x);
  }
  
  if (shot_dir_y < 0)
  {
    step_y = -1;
    side_y = (ray_pos_y - s->map->m_y) * fabs(1 / s->map->rd_y);
  }
  else
  {
    step_y = 1;
    side_y = (s->map->m_y + 1.0 - ray_pos_y) * fabs(1 / s->map->rd_y);
  }

  while (hit_wall == 0)
  {
    if (side_x < side_y)
    {
      side_x += fabs(1 / s->map->rd_x);
      s->map->m_x += step_x;
    }
    else
    {
      side_y += fabs(1 / s->map->rd_y);
      s->map->m_x += step_y;
    }
    int a = 10;
    SDL_Rect fire_rect;
    fire_rect.x = WIDTH/2 -50;
    fire_rect.y = HEIGHT/2 - 50;
    fire_rect.w = 100;
    fire_rect.h = 100;
    fire_rect.w -= a;
    fire_rect.h -= a;
    //SDL_BlitSurface(fire, NULL, s->win_surface, NULL);
    //SDL_Delay(200);
    SDL_BlitScaled(fire, NULL, s->win_surface, &fire_rect);
    //SDL_Delay(200);
    if (s->floor[s->map->m_x][s->map->m_y] > 0)
      hit_wall = 1;
    // else
    // {
    //   SDL_BlitSurface(fire, NULL, s->win_surface, NULL);
    // }
  }
  
}

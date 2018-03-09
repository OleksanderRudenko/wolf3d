#include "woof.h"

void  maluy_stinu(t_sdl_manange *s)
{
  s->map->x = -1;
  while (++s->map->x < WIDTH)
  {
    init_for_wall(s);
    init_for_wall2(s);
    was_hit(s);
    s->map->l_h = (int)(HEIGHT / s->map->pwd);
    s->map->dr_s = -s->map->l_h / 2 + HEIGHT / 2;
    if (s->map->dr_s < 0)
      s->map->dr_s = 0;
    s->map->dr_e = s->map->l_h / 2 + HEIGHT / 2;
    if (s->map->dr_e >= HEIGHT)
      s->map->dr_e = HEIGHT - 1;
    davay_textyry(s);
    init_for_wall3(s);
    while (++s->map->y < s->map->dr_e)
    {
      s->map->d = s->map->y * 256 - HEIGHT * 128 + s->map->l_h * 128;
      s->map->t_y = ((s->map->d * 64 / s->map->l_h) / 256);
      *s->map->buffer = ((unsigned int *)s->im_surf[s->map->n]->pixels)[64 * s->map->t_y + s->map->t_x];
      s->map->buffer += WIDTH;
    }
    maluy_pidlogu_ta_stelu(s);
  }
}

void  init_for_wall(t_sdl_manange *s)
{
      s->map->ra = 2 * s->map->x / (float)(WIDTH)-1;
      s->map->rd_x = s->map->dir_x + s->map->plane_x * s->map->ra;
      s->map->rd_y = s->map->dir_y + s->map->plane_y * s->map->ra;
      s->map->m_x = (int)(s->map->ppos_x);
      s->map->m_y = (int)(s->map->ppos_y);
      s->map->dd_x = fabs(1 / s->map->rd_x);
      s->map->dd_y = fabs(1 / s->map->rd_y);
      s->map->hit = 0;
}

void  init_for_wall2(t_sdl_manange *s)
{
  if (s->map->rd_x < 0)
  {
    s->map->st_x = -1;
    s->map->rlx = (s->map->ppos_x - s->map->m_x) * s->map->dd_x;
  }
  else
  {
    s->map->st_x = 1;
    s->map->rlx = (s->map->m_x + 1.0 - s->map->ppos_x) * s->map->dd_x;
  }
  if (s->map->rd_y < 0)
  {
    s->map->st_y = -1;
    s->map->rly = (s->map->ppos_y - s->map->m_y) * s->map->dd_y;
  }
  else
  {
    s->map->st_y = 1;
    s->map->rly = (s->map->m_y + 1.0 - s->map->ppos_y) * s->map->dd_y;
  }
}

void was_hit(t_sdl_manange *s)
{
  while (s->map->hit == 0)
  {
    if (s->map->rlx < s->map->rly)
    {
      s->map->rlx += s->map->dd_x;
      s->map->m_x += s->map->st_x;
      s->map->side = 0;
    }
    else
    {
      s->map->rly += s->map->dd_y;
      s->map->m_y += s->map->st_y;
      s->map->side = 1;
    }
    s->map->hit = s->floor[s->map->m_x][s->map->m_y] > 0 ? 1 : 0;
  }
  if (s->map->side == 0)
    s->map->pwd = (s->map->m_x - s->map->ppos_x + (1 - s->map->st_x) / 2) / s->map->rd_x;
  else
    s->map->pwd = (s->map->m_y - s->map->ppos_y + (1 - s->map->st_y) / 2) / s->map->rd_y;
}

void davay_textyry(t_sdl_manange *s)
{
  if (s->floor[s->map->m_x][s->map->m_y] == 1)
    s->map->n = 0;
  else if (s->floor[s->map->m_x][s->map->m_y] == 2)
    s->map->n = 1;
  else if (s->floor[s->map->m_x][s->map->m_y] == 3)
    s->map->n = 2;
  else if (s->floor[s->map->m_x][s->map->m_y] == 4)
    s->map->n = 3;
  else if (s->floor[s->map->m_x][s->map->m_y] == 6)
    s->map->n = 4;
  else
    s->map->n = 0;
  if (s->map->side == 0)
    s->map->w_x = s->map->ppos_y + s->map->pwd * s->map->rd_y;
  else
    s->map->w_x = s->map->ppos_x + s->map->pwd * s->map->rd_x;
  s->map->w_x -= floor(s->map->w_x);
}

void init_for_wall3(t_sdl_manange *s)
{
  s->map->t_x = (int)(s->map->w_x * (double)(64));
  if (s->map->side == 0 && s->map->rd_x > 0)
    s->map->t_x = 64 - s->map->t_x - 1;
  if (s->map->side == 1 && s->map->rd_y < 0)
    s->map->t_x = 64 - s->map->t_x - 1;
  s->map->y = s->map->dr_s - 1;
  s->map->buffer = (unsigned int *)s->win_surface->pixels + s->map->dr_s * s->win_surface->w + s->map->x;
}
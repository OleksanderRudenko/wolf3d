#include "woof.h"


int			key_hook(t_sdl_manange *s)
{
    //move forward if no wall in front of you
    if (SDL_PollEvent(&s->event))
    {
      if (s->event.key.keysym.sym == SDLK_w)
      {
        if(s->floor[(int)(s->map->ppos_x + s->map->dir_x * s->map->mv_speed)][(int)(s->map->ppos_y)] == 0)
        {
          s->map->ppos_x += s->map->dir_x * s->map->mv_speed;
        }
        if(s->floor[(int)(s->map->ppos_x)][(int)(s->map->ppos_y + s->map->dir_y * s->map->mv_speed)] == 0)
        {
          s->map->ppos_y += s->map->dir_y * s->map->mv_speed;
        }
      }
      // //move backwards if no wall behind you
      if (s->event.key.keysym.sym == SDLK_s)
      {
        if(s->floor[(int)(s->map->ppos_x - s->map->dir_x * s->map->mv_speed)][(int)(s->map->ppos_y)] == 0)
        {
          s->map->ppos_x -= s->map->dir_x * s->map->mv_speed;
        }
        if(s->floor[(int)(s->map->ppos_x)][(int)(s->map->ppos_y - s->map->dir_y * s->map->mv_speed)] == 0)
        {
          s->map->ppos_y -= s->map->dir_y * s->map->mv_speed;
        }
      }
      // //rotate to the right
      if (s->event.key.keysym.sym == SDLK_d)
      {
        //both camera direction and camera plane must be rotated
        double oldDirX = s->map->dir_x;
        s->map->dir_x = s->map->dir_x * cosf(-s->map->rot_speed) - s->map->dir_y * sinf(-s->map->rot_speed);
        s->map->dir_y = oldDirX * sinf(-s->map->rot_speed) + s->map->dir_y * cosf(-s->map->rot_speed);
        double oldPlaneX = s->map->pangle_x;
        s->map->pangle_x = s->map->pangle_x * cosf(-s->map->rot_speed) - s->map->pangle_y * sinf(-s->map->rot_speed);
        s->map->pangle_y = oldPlaneX * sinf(-s->map->rot_speed) + s->map->pangle_y * cosf(-s->map->rot_speed);
      }
      // //rotate to the left
      if (s->event.key.keysym.sym == SDLK_a)
      {
        //both camera direction and camera plane must be rotated
        double oldDirX = s->map->dir_x;
        s->map->dir_x = s->map->dir_x * cos(s->map->rot_speed) - s->map->dir_y * sin(s->map->rot_speed);
        s->map->dir_y = oldDirX * sin(s->map->rot_speed) + s->map->dir_y * cos(s->map->rot_speed);
        double oldPlaneX = s->map->pangle_x;
        s->map->pangle_x = s->map->pangle_x * cos(s->map->rot_speed) - s->map->pangle_y * sin(s->map->rot_speed);
        s->map->pangle_y = oldPlaneX * sin(s->map->rot_speed) + s->map->pangle_y * cos(s->map->rot_speed);
      }
    }
     return (0);
}

void	print_list(t_flist *begin)
{
  t_flist *tmp;
  tmp = begin;
	while (tmp->next != NULL)
	{
		ft_putendl(tmp->line);
		tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
  t_sdl_manange wolf;
  
  wolf.begin = read_file(argv[1]);
  init_values(&wolf);
 
  while (1)
  {
      if (SDL_PollEvent(&wolf.event))
    {
      if (wolf.event.type == SDL_QUIT)
        break;
      if (wolf.event.key.keysym.sym == SDLK_ESCAPE)
        break;
    }
      ft_bzero(wolf.win_surface->pixels, WIDTH * HEIGHT * 4);
      key_hook(&wolf);
      maluy_stinu(&wolf);
      SDL_UpdateWindowSurface(wolf.win);
  }
  SDL_DestroyWindow(wolf.win);
	return (0);
}

#include "woof.h"


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
// # define LEAK system("leaks $(echo $(ps | grep fdf | cut -d ' ' -f 1) | cut -d ' ' -f 2) && leaks $(echo $(ps | grep fdf | cut -d ' ' -f 1) | cut -d ' ' -f 1)");
int		main(int argc, char **argv)
{
  t_sdl_manange wolf;
  
  wolf.begin = read_file(argv[1]);
  init_values(&wolf);
  load_music(&wolf);
  load_weapon(&wolf);
  IMG_Init(IMG_INIT_PNG);
  ///////////


///////////////////////////////AUDIO

//////////
// surface = SDL_DisplayFormat(surface);  // memory leak!!

// // correct version
// NewSurface = SDL_DisplayFormat(surface);
// SDL_FreeSurface(surface);
/////////////
int a = menu(&wolf);

  while (a == 1)
  {
    if (!poll_event(&wolf))
      return (0);
    ft_bzero(wolf.win_surface->pixels, WIDTH * HEIGHT * 4);
    maluy_stinu(&wolf);
    draw_sight(&wolf);
    SDL_BlitScaled(wolf.chainsaw[wolf.num], NULL,wolf.win_surface, &wolf.chain_rect); //weapon
    SDL_UpdateWindowSurface(wolf.win);
  }
  IMG_Quit();
  Mix_Quit();
  pochistu_vse(&wolf);
	return (0);
}
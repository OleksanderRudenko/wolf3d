#include "woof.h"

void  init_values(t_sdl_manange *s)
{
	char	**pos;
	
	count_symbols(s->begin);
	s->floor = init_floor(s);
	load_textures(s);
	s->win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT+100, SDL_WINDOW_OPENGL);
	s->win_surface = SDL_GetWindowSurface(s->win);
	pos = ft_strsplit(s->begin->param, ' ');
	s->map = (t_wolf *)malloc(sizeof(t_wolf));
	s->map->ppos_x = (float)ft_atoi(pos[0]);
	s->map->ppos_y = (float)ft_atoi(pos[1]);;
	s->map->dir_x = -1;
	s->map->dir_y = 0;
	s->map->plane_x = 0;
	s->map->plane_y = 0.66;
	s->map->mv_speed = 0.3f;
	s->map->rot_speed = 0.05f;
	s->map->hit = 0;
	s->map->n = 0;
	s->num = 0;
	s->active_gun = 0;
	s->shoot = 0;
	init_text(s);
	free_double(pos);
}

void	load_music(t_sdl_manange *s)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
  		ft_putendl(Mix_GetError());
	s->sound.chunks[0] = Mix_LoadWAV("music/Chain.mp3");
	if (s->sound.chunks[0] == NULL)
		ft_putendl(Mix_GetError());
	s->sound.chunks[1] = Mix_LoadWAV("music/Shotgun.mp3");
	if (s->sound.chunks[1] == NULL)
		ft_putendl(Mix_GetError());
	s->sound.back = Mix_LoadMUS("music/HBT.mp3");
	if (s->sound.back == NULL)
		ft_putendl(Mix_GetError());
	Mix_PlayMusic(s->sound.back, -1);
	Mix_VolumeMusic(5);
}

void	load_textures(t_sdl_manange *s)
{
	s->im_surf = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 8);
	s->im_surf[0] = load_image("pic/bluestone.bmp");
	s->im_surf[1] = load_image("pic/pw.bmp");
	s->im_surf[2] = load_image("pic/st.bmp");
	s->im_surf[3] = load_image("pic/cs.bmp");
	s->im_surf[4] = load_image("pic/mossy.bmp");
	s->im_surf[5] = load_image("pic/gs.bmp");
	s->im_surf[6] = load_image("pic/ceil.bmp");
	s->im_surf[7] = load_image("pic/barrel.png");
}

void	load_weapon(t_sdl_manange *s)
{
	s->status_line = load_image("pic/line.png");
	s->line_rect.x = 0;
	s->line_rect.y = HEIGHT;
	s->line_rect.h = 100;
	s->line_rect.w = WIDTH;
	init_sprite(&s->guns[0], "pic/chain", 2);
	s->guns[0].rect.x = WIDTH/2 -75;
	s->guns[0].rect.y = HEIGHT-250;
	s->guns[0].rect.h = 250;
	s->guns[0].rect.w = 250;
	init_sprite(&s->guns[1], "pic/s", 6);
	s->guns[1].rect.x = WIDTH / 2 - 100;
    s->guns[1].rect.y = HEIGHT - 200;
    s->guns[1].rect.h = 200;
    s->guns[1].rect.w = 200;
	init_sprite(&s->guns[2], "pic/r", 4);
	s->guns[2].rect.x = WIDTH / 2 - 100;
    s->guns[2].rect.y = HEIGHT - 200;
    s->guns[2].rect.h = 200;
    s->guns[2].rect.w = 300;
	s->active_gun = 0;
}

void	draw_sight(t_sdl_manange *s)
{
	int i;

	i = -15;
	s->map->sight = (unsigned int *)s->win_surface->pixels;
	while (i < 15)
    {
      s->map->sight[HEIGHT * WIDTH / 2 + WIDTH / 2 + i] = 0xff0000; // horiz
	  s->map->sight[HEIGHT * WIDTH / 2 + (i*WIDTH + WIDTH /2)] = 0xff0000; // vert
	  i++;
    }
}

void	fck_up()
{
	ft_putendl("usage: ./wolf3d [map name]");
	exit (0);
}

void	mal_er()
{
	ft_putendl("Malloc fails");
	exit (0);
}

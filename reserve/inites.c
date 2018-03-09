#include "woof.h"

void  init_values(t_sdl_manange *s)
{
	char	**pos;
	count_symbols(s->begin);
	s->floor = init_floor(s);
	load_textures(s);
	SDL_Init(SDL_INIT_EVERYTHING);
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
	s->map->mv_speed = 0.5f;
	s->map->rot_speed = 0.1f;
	s->map->hit = 0;
	s->map->n = 0;
	s->num = 0;
	//s->map->chain = Mix_LoadMUS("music/Chain.mp3");
	free_double(pos);
}

void	load_music(t_sdl_manange *s)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
  		ft_putendl(Mix_GetError());
	s->sound.chain = Mix_LoadWAV("music/Chain.mp3");
	if (s->sound.chain == NULL)
		ft_putendl(Mix_GetError());
	s->sound.back = Mix_LoadMUS("music/HBT.mp3");
	if (s->sound.back == NULL)
		ft_putendl(Mix_GetError());
	Mix_PlayMusic(s->sound.back, -1);
	Mix_VolumeMusic(5);
}
void	pochistu_vse(t_sdl_manange *s)
{
	Mix_FreeChunk(s->sound.chain);
	s->sound.chain = NULL;
	free(s->map);
	SDL_FreeSurface(s->win_surface);
	s->win_surface = NULL;
	// SDL_FreeSurface(s->im_surf[0]);
	// s->im_surf[0] = NULL;
	SDL_DestroyWindow(s->win);
	s->win = NULL;
	SDL_Quit();
	//TODO NUll all images and music
}

void	load_textures(t_sdl_manange *s)
{
	s->im_surf = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 7);

	s->im_surf[0] = load_surf("pic/bluestone.bmp");
	s->im_surf[0] = SDL_ConvertSurfaceFormat(s->im_surf[0], SDL_PIXELFORMAT_ARGB8888, 0);

	s->im_surf[1] = load_surf("pic/pw.bmp");
	s->im_surf[1] = SDL_ConvertSurfaceFormat(s->im_surf[1], SDL_PIXELFORMAT_ARGB8888, 0);

	s->im_surf[2] = load_surf("pic/st.bmp");
	s->im_surf[2] = SDL_ConvertSurfaceFormat(s->im_surf[2], SDL_PIXELFORMAT_ARGB8888, 0);

	s->im_surf[3] = load_surf("pic/cs.bmp");
	s->im_surf[3] = SDL_ConvertSurfaceFormat(s->im_surf[3], SDL_PIXELFORMAT_ARGB8888, 0);
  
	s->im_surf[4] = load_surf("pic/mossy.bmp");
	s->im_surf[4] = SDL_ConvertSurfaceFormat(s->im_surf[4], SDL_PIXELFORMAT_ARGB8888, 0);

	s->im_surf[5] = load_surf("pic/floor.bmp");
	s->im_surf[5] = SDL_ConvertSurfaceFormat(s->im_surf[5], SDL_PIXELFORMAT_ARGB8888, 0);

	s->im_surf[6] = load_surf("pic/ceil.bmp");
	s->im_surf[6] = SDL_ConvertSurfaceFormat(s->im_surf[6], SDL_PIXELFORMAT_ARGB8888, 0);

}

void	load_weapon(t_sdl_manange *s)
{
	s->chainsaw[0] = IMG_Load("pic/css.png");
	s->chainsaw[1] = IMG_Load("pic/chain2.png");
	s->chain_rect.x = WIDTH/2 -75;
	s->chain_rect.y = HEIGHT-250;
	s->chain_rect.h = 250;
	s->chain_rect.w = 250;
}

void	draw_sight(t_sdl_manange *s)
{
	s->map->sight = (unsigned int *)s->win_surface->pixels;
	for(int i = -15; i < 15; ++i)
    {
      s->map->sight[HEIGHT * WIDTH / 2 + WIDTH / 2 + i] = 0xff0000; // horiz
      s->map->sight[HEIGHT * WIDTH / 2 + (i*WIDTH + WIDTH /2)] = 0xff0000; // vert
    }
}

int	**init_floor(t_sdl_manange *s)
{
	int i;
	int j;
	int	**arr;
	char **paiste;
	t_flist *tmp;

	i = -1;
	tmp = s->begin;
	arr = (int **)malloc(sizeof(int *) * tmp->vert);
	while (++i < tmp->vert)
	{
		j = -1;
		arr[i] = (int *)malloc(sizeof(int) * tmp->hor);
		paiste = ft_strsplit(tmp->line, ' ');
		while (++j < tmp->hor)
		{
			arr[i][j] = ft_atoi(paiste[j]);
		}
		free_double(paiste);
		tmp = tmp->next;
	}
	return (arr);
}

t_flist		*read_file(char *str)
{
	int			fd;
	char		*line;
	t_flist		*xd;
	t_flist		*tmp;
	
	if ((fd = open(str, O_RDONLY)) == -1)
		fck_up();
	xd = (t_flist *)malloc(sizeof(t_flist));
	tmp = xd;
	if (get_next_line(fd, &line) < 0)
		fck_up();
	tmp->param = ft_strdup(line);
	ft_strdel(&line);
	while (get_next_line(fd, &line) > 0)
	{
		tmp->line = ft_strdup(line);
		tmp->next = (t_flist *)malloc(sizeof(t_flist));
		tmp = tmp->next;
		ft_strdel(&line);
	}
	tmp->next = NULL;
	close(fd);
	return (xd);
}

void		count_symbols(t_flist *head)
{
	t_flist		*tmp;
	int			horiz;
	int			vertic;

	tmp = head;
	horiz = ft_num_words(head->line, ' ');
	vertic = list_size(head);
	while (tmp->next)
	{
		tmp->hor = ft_num_words(tmp->line, ' ');
		if (tmp->hor != horiz)
		{
			ft_putendl("Error: wrong num of lines");
			exit(0);
		}
		tmp->vert = vertic;
		tmp = tmp->next;
	}
}

int		list_size(t_flist *head)
{
	int		i;
	t_flist	*tmp;

	tmp = head;
	i = 0;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
void	free_double(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_strdel(&s[i]);
		i++;
	}
	free(s);
	s = NULL;
}

void	fck_up()
{
	ft_putendl("usage: ./wolf3d [map name]");
	exit (0);
}
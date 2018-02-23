#include "woof.h"

void  init_values(t_sdl_manange *s)
{
	char	**pos;

	pos = ft_strsplit(s->begin->param, ' ');
	s->map = (t_wolf *)malloc(sizeof(t_wolf));
	s->map->ppos_x = (float)ft_atoi(pos[0]);
	s->map->ppos_y = (float)ft_atoi(pos[1]);;
	s->map->dir_x = -1;
	s->map->dir_y = 0;
	s->map->pangle_x = 0;
	s->map->pangle_y = 0.66;
	s->map->mv_speed = 0.5f;
	s->map->rot_speed = 0.2f;
	free_double(pos);
}

void	load_textures(t_sdl_manange *s)
{
	s->im_surf = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 5);

	s->im_surf[0] = load_surf("pic/bs.bmp");
	s->im_surf[0] = SDL_ConvertSurfaceFormat(s->im_surf[0], SDL_PIXELFORMAT_ARGB8888, 0);

	s->im_surf[1] = load_surf("pic/redbrick.bmp");
	s->im_surf[1] = SDL_ConvertSurfaceFormat(s->im_surf[1], SDL_PIXELFORMAT_ARGB8888, 0);

	s->im_surf[2] = load_surf("pic/gs.bmp");
	s->im_surf[2] = SDL_ConvertSurfaceFormat(s->im_surf[2], SDL_PIXELFORMAT_ARGB8888, 0);

	s->im_surf[3] = load_surf("pic/cs.bmp");
	s->im_surf[3] = SDL_ConvertSurfaceFormat(s->im_surf[3], SDL_PIXELFORMAT_ARGB8888, 0);
  
	s->im_surf[4] = load_surf("pic/mossy.bmp");
	s->im_surf[4] = SDL_ConvertSurfaceFormat(s->im_surf[4], SDL_PIXELFORMAT_ARGB8888, 0);
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
		tmp = tmp->next;
	}
	free_double(paiste);
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
	get_next_line(fd, &line);
	tmp->param = ft_strdup(line);
	ft_strdel(&line);
	while ((get_next_line(fd, &line)))
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
	ft_putendl("Do not play dirty games with me!");
	ft_putendl("Come on, gimme horny file");
	exit (0);
}

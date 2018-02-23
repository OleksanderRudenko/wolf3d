#ifndef WOOF_H
#define WOOF_H

#include <SDL.h>
#include <math.h>
#include <stdlib.h>
# include "./libft/libft.h"

#define mapWidth 24
#define mapHeight 24
#define WIDTH 1024
#define HEIGHT 768

typedef struct s_wolf
{
	float	ppos_x; // player pos x
	float	ppos_y; // player pos y
	float	dir_x;
	float	dir_y;
	float	pangle_x;
	float	pangle_y;
	float	mv_speed;
	float	rot_speed;
	unsigned int *buffer;
}				t_wolf;

typedef struct 		s_sdl_manage
{
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Surface		**im_surf;
	SDL_Surface		*win_surface;
	int				**floor;
	t_wolf			*map;
	struct s_flist	*begin;
}     				t_sdl_manange;

typedef struct	s_flist
{
	int			hor;
	int			vert;
	char		*line;
	char		*param;
	struct s_flist *next;
}				t_flist;

void  init_values(t_sdl_manange *s);
SDL_Surface *load_surf(char *filepath);
void	load_textures(t_sdl_manange *s);
//int			key_function(t_sdl_manange *s);
t_flist		*read_file(char *str);
void		count_symbols(t_flist *head);
int		list_size(t_flist *head);
void	free_double(char **s);
int	**init_floor(t_sdl_manange *s);
void	fck_up();
#endif

#ifndef WOOF_H
#define WOOF_H

#include <SDL.h>
#include <math.h>
#include <mlx.h>
#include <stdlib.h>
# include "./libft/libft.h"

#define mapWidth 24
#define mapHeight 24
#define WIDTH 640
#define HEIGHT 640
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_RIGHT 124
#define KEY_LEFT 123
#define NUM_TEXTURES 5
#define TEXTURE_H 64
#define TEXTURE_W 64

typedef struct 		s_wolf2
{
	SDL_Window		*win;
	SDL_Event		window_event;
	SDL_Surface		*image_surf;
	SDL_Surface		*image_surf2;
	SDL_Surface		**walls_textures;
	SDL_Surface		*current_image;
	SDL_Surface		*win_surf;
	SDL_Rect		draw_rect;
	SDL_Renderer	*rend;
	SDL_Texture		*curr_texture;
}     t_wolf2;

typedef struct 		s_wolf
{
	void			        *mlx;
	void			        *win;
    struct s_im             *im;
	struct s_put_image		*mal;
	struct s_map			*map;
	struct s_textures		*textur;
}                   t_wolf;

typedef struct	s_put_image
{
    void		*d_pic;
    char		*pic;
    int			bpp;
    int			s_l;
    int			end;
    int			color;
	int			pixel;
}				t_put_image;

typedef struct	s_im
{
	int		a;
	int		b;
	int		c;
	int		color;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		x0;//start point
	int		y0;//start point
	int		x1;//end point
	int		y1;//end point
	int		x;
	int		y;
	int		d;
	int		d1;
	int		d2;
	int		length;
}				t_im;

typedef struct s_map
{
	float	ppos_x; // player pos x
	float	ppos_y; // player pos y
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}				t_map;

typedef struct s_textures
{
	int			bpp;
    int			s_l;
	void		*file;
	int			end;
	int			width;
	int			height;
	char		*lll;
}				t_texures;

void	get_image(t_wolf *one);
void    pixel_image(char *one, int x, int y, int color);
void    ar_line(t_wolf *one, t_im *s);
void  draw_map(t_wolf *one);
void  init_values(t_wolf *one);
void get_textures(t_wolf *one);
//SDL_Surface *load_texture(char *filepath, SDL_Renderer *render_target);

#endif
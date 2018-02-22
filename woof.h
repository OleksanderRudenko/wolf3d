#ifndef WOOF_H
#define WOOF_H

#include <SDL2/SDL.h>
#include <math.h>
#include "./libft/libft.h"
#include <stdlib.h>
#include "./minilibx/mlx.h"

#define mapWidth 24
#define mapHeight 24
#define WIDTH 640
#define HEIGHT 640
#define NUM_TEXTURES 5
#define TEXTURE_H 64
#define TEXTURE_W 64
// #define KEY_UP 126
// #define KEY_DOWN 125
// #define KEY_RIGHT 124
// #define KEY_LEFT 123

//////linux
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_RIGHT 65363
#define KEY_LEFT 65361


typedef struct 		s_woof
{
	SDL_Window		*win;
	SDL_Surface		*im_surf;
	SDL_Surface		*window_surface;

}					t_woof;
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

void  draw_map(t_wolf *one, t_woof *s);

void  init_values(t_wolf *one);
void get_textures(t_wolf *one);
SDL_Surface *load_surf(char *filepath);
#endif

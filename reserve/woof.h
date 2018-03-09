#ifndef WOOF_H
#define WOOF_H

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <math.h>
#include "./libft/libft.h"
#include <stdlib.h>


#define WIDTH 1024
#define HEIGHT 768

typedef struct s_wolf
{
	float	ppos_x; // player pos x
	float	ppos_y; // player pos y
	float	dir_x;
	float	dir_y;
	float	plane_x; //player angle x
	float	plane_y; //player angle y
	float	mv_speed;
	float	rot_speed;
	float	ra; //ray_angle
	float	rd_x; // ray direction
	float	rd_y;
	float	rlx; //ray len x
	float	rly;//ray len y
	unsigned int *buffer;
	unsigned int *sight;
	int		hit;
	float	dd_x;//delta dist x
	float	dd_y;
	int		m_x;//map x
	int		m_y;//map y
	int		st_x; //step x
	int		st_y; //step y
	int		side;
	float	pwd; //perpWallDist
	int		l_h; // line height
	int		dr_s; // draw start
	int		dr_e;// draw end
	int		d;
	int		t_x; //texX
	int		t_y;// texY
	int		y;
	int		x;
	int		n;
	float	w_x; // wall x

}				t_wolf;

typedef struct s_sound
{
	Mix_Chunk		*chain;
	Mix_Music 		*back;
}				t_sound;

typedef struct 		s_sdl_manage
{
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Surface		**im_surf;
	SDL_Surface		*win_surface;
	SDL_Surface		*chainsaw[2];
	SDL_Rect		chain_rect;
	int				**floor;
	t_wolf			*map;
	int				num;
	struct s_flist	*begin;
	struct s_sound	sound;
	
}     				t_sdl_manange;

typedef struct	s_flist
{
	int			hor;
	int			vert;
	char		*line;
	char		*param;
	struct s_flist *next;
}				t_flist;

void  		init_values(t_sdl_manange *s);
SDL_Surface *load_surf(char *filepath);
void		load_textures(t_sdl_manange *s);
t_flist		*read_file(char *str);
void		count_symbols(t_flist *head);
int			list_size(t_flist *head);
void		free_double(char **s);
int			**init_floor(t_sdl_manange *s);
void		fck_up();
void		maluy_stinu(t_sdl_manange *s);
void		was_hit(t_sdl_manange *s);
void		init_for_wall(t_sdl_manange *s);
void		init_for_wall2(t_sdl_manange *s);
void		init_for_wall3(t_sdl_manange *s);
void		davay_textyry(t_sdl_manange *s);

void    maluy_pidlogu_ta_stelu(t_sdl_manange *s);
void 	idu_vpered(t_sdl_manange *s);
void 	idu_nazad(t_sdl_manange *s);
void 	povernu_napravo(t_sdl_manange *s);
void povernu_nalivo(t_sdl_manange *s);
int   poll_event(t_sdl_manange *s);
void  key_down(SDL_Keycode key, t_sdl_manange *s);
void  mouse_down_event(SDL_Keycode key, t_sdl_manange *s);

void	pochistu_vse(t_sdl_manange *s);
void  shoot(t_sdl_manange *s);
void	load_music(t_sdl_manange *s);
void	load_weapon(t_sdl_manange *s);
void	draw_sight(t_sdl_manange *s);
int menu(t_sdl_manange *s);
#endif

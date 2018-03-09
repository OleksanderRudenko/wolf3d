#ifndef WOOF_H
#define WOOF_H

#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <math.h>
#include "./libft/libft.h"

# define WIDTH 1280
# define HEIGHT 1024
#define NUM_GUNS 3

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

typedef struct	s_sprite
{
	SDL_Surface	**frames;
	SDL_Rect    rect;
    int fps;
    int frametime;
	int numframes;
	int	frametime_faces;
	int	fps_face;
	int	sn_face;
	int	sn;
	int	active;
	int loop;
}				t_sprite;

typedef struct s_sound
{
	Mix_Chunk		*chunks[2];
	Mix_Music 		*back;
}				t_sound;

typedef struct	s_text
{
	TTF_Font	*font;
	SDL_Surface	*mesaga;
	SDL_Rect	text_rect;
	SDL_Color	text_color;
	int			bullet_left;
}				t_text;

typedef struct	s_obj // struct for objects on map (like barrels)
{
	float		sp_x;
	float		sp_y;
	float		inv_det;
	float		tr_x;
	float		tr_y;
	int			sprt_h;
	int			start_x;
	int			start_y;
	int			texture_x;
}				t_obj;

typedef struct	s_flist
{
	int			hor;
	int			vert;
	char		*line;
	char		*param;
	struct s_flist *next;
}				t_flist;

typedef struct 		s_sdl_manage
{
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Surface		**im_surf;
	SDL_Surface		*win_surface;
	SDL_Surface		*status_line;
	SDL_Rect		line_rect;
	SDL_Rect		chain_rect;
	int				**floor;
	t_wolf			*map;
	int				num;
	struct s_flist	*begin;
	t_sprite		guns[NUM_GUNS];
	t_sprite		face;
	t_text			text;
	t_obj			obj;
	SDL_Rect		face_rect;
	int				active_gun;
	SDL_Surface **menus;
	SDL_Rect    im[2];
	int				shoot;
	struct s_sound	sound;
}     				t_sdl_manange;


void	mal_er();
void  		init_values(t_sdl_manange *s);
SDL_Surface *load_surf(char *filepath);
SDL_Surface	*load_image(char *filepath);
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
/*MUSIC*/
void	load_music(t_sdl_manange *s);
void	del_music(t_sdl_manange *s);
/* */

void	load_weapon(t_sdl_manange *s);
void	draw_sight(t_sdl_manange *s);
int menu(t_sdl_manange *s);
void    init_sprite(t_sprite *s, char *file, int num);
void    draw_sprite(t_sprite *s, t_sdl_manange *m);
void    delete_sprite(t_sprite *s);

void    load_face(t_sdl_manange *s);
void    show_face(t_sprite *s, t_sdl_manange *m);
/*text*/
void    init_text(t_sdl_manange *s);
void	sprite_line(t_sdl_manange *s, int x);

///
void    del_surf_inmenu(t_sdl_manange *s, int num);
void    init_menu(t_sdl_manange *s);

void    constructor_lego(t_sdl_manange *s);
void    destructor_lego(t_sdl_manange *s);

void    print_text_on_screen(t_sdl_manange *s, int text);
#endif

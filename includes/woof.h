/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woof.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:21:05 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/28 14:23:36 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOOF_H
# define WOOF_H

# include "SDL2/SDL.h"
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
# include <math.h>
# include "libft.h"

# define WIDTH 1280
# define HEIGHT 1024
# define NUM_GUNS 4

typedef struct		s_wolf
{
	float			ppos_x;
	float			ppos_y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
	float			mv_speed;
	float			rot_speed;
	float			ra;
	float			rd_x;
	float			rd_y;
	float			rlx;
	float			rly;
	unsigned int	*buffer;
	unsigned int	*sight;
	int				hit;
	float			dd_x;
	float			dd_y;
	int				m_x;
	int				m_y;
	int				st_x;
	int				st_y;
	int				side;
	float			pwd;
	int				l_h;
	int				dr_s;
	int				dr_e;
	int				d;
	int				t_x;
	int				t_y;
	int				y;
	int				x;
	int				n;
	float			w_x;
	float			fl_xwall;
	float			fl_ywall;
	float			dist_wall;
	float			curr_dist;
	float			weight;
	int				fl_tx;
	int				fl_ty;
}					t_wolf;

typedef struct		s_sprite
{
	SDL_Surface		**frames;
	SDL_Rect		rect;
	int				fps;
	int				frametime;
	int				numframes;
	int				frametime_faces;
	int				fps_face;
	int				sn_face;
	int				sn;
	int				active;
	int				loop;
}					t_sprite;

typedef struct		s_sound
{
	Mix_Chunk		*chunks[5];
	Mix_Music		*back;
}					t_sound;

typedef struct		s_text
{
	TTF_Font		*font;
	SDL_Surface		*mesaga;
	SDL_Rect		text_rect;
	SDL_Color		text_color;
	int				bullet_left;
}					t_text;

typedef struct		s_obj
{
	float			sp_x;
	float			sp_y;
	float			inv_det;
	float			tr_x;
	float			tr_y;
	int				sprt_h;
	int				start_x;
	int				start_y;
	int				texture_x;
}					t_obj;

typedef struct		s_flist
{
	int				hor;
	int				vert;
	char			*line;
	char			*param;
	struct s_flist	*next;
}					t_flist;

typedef struct		s_sdl_manage
{
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Event		ev;
	SDL_Surface		**im_surf;
	SDL_Surface		*win_surface;
	SDL_Surface		*status_line;
	SDL_Rect		line_rect;
	SDL_Rect		chain_rect;
	int				**floor;
	t_wolf			*map;
	int				num;
	struct s_flist	*begin;
	t_sprite		*guns;
	t_sprite		face;
	t_sprite		fuck;
	t_text			text;
	t_obj			obj;
	SDL_Rect		face_rect;
	int				active_gun;
	int				current_gun;
	SDL_Surface		**menus;
	SDL_Rect		im[2];
	int				shoot;
	int				x;
	int				y;
	struct s_sound	sound;
}					t_sdl_manange;

void				mal_er(void);
void				init_values(t_sdl_manange *s);
SDL_Surface			*load_surf(char *filepath);
SDL_Surface			*load_image(char *filepath);
void				load_textures(t_sdl_manange *s);
t_flist				*read_file(char *str);
void				count_symbols(t_flist *head);
int					list_size(t_flist *head);
void				free_double(char **s);
int					**init_floor(t_sdl_manange *s);
void				fck_up(void);
void				maluy_stinu(t_sdl_manange *s);
void				was_hit(t_sdl_manange *s);
void				init_for_wall(t_sdl_manange *s);
void				init_for_wall2(t_sdl_manange *s);
void				init_for_wall3(t_sdl_manange *s);
void				davay_textyry(t_sdl_manange *s);
void				maluy_pidlogu_ta_stelu(t_sdl_manange *s);
void				idu_vpered(t_sdl_manange *s);
void				idu_nazad(t_sdl_manange *s);
void				povernu_napravo(t_sdl_manange *s);
void				povernu_nalivo(t_sdl_manange *s);
int					poll_event(t_sdl_manange *s);
void				key_down(SDL_Scancode key, t_sdl_manange *s);
void				mouse_down_event(SDL_Keycode key, t_sdl_manange *s);
void				pochistu_vse(t_sdl_manange *s);
void				load_music(t_sdl_manange *s);
void				del_music(t_sdl_manange *s);
void				load_weapon(t_sdl_manange *s);
void				draw_sight(t_sdl_manange *s);
int					menu(t_sdl_manange *s);
void				init_sprite(t_sprite *s, char *file, int num);
void				draw_sprite(t_sprite *s, t_sdl_manange *m);
void				delete_sprite(t_sprite *s);
void				load_face(t_sdl_manange *s);
void				show_face(t_sprite *s, t_sdl_manange *m);
void				init_text(t_sdl_manange *s);
void				sprite_line(t_sdl_manange *s, int x);
int					del_surf_inmenu(t_sdl_manange *s, int num, int flag);
void				init_menu(t_sdl_manange *s);
void				constructor_lego(t_sdl_manange *s);
void				destructor_lego(t_sdl_manange *s);
void				print_text_on_screen(t_sdl_manange *s, int text);
void				init_floor_c(t_sdl_manange *s);
void				line_er(void);
void				bad_position(void);
void				xd(t_sdl_manange *s);
void				if_mouse_motion_menu(t_sdl_manange *s, int x, int y);
void				init_for_sprite(t_sdl_manange *s, t_obj *o, int *n);
int					loll(t_sdl_manange *s);
void				check_valid_map(t_sdl_manange *s);
int					ft_isalpha_str(char *s);
void				check_valid_map2(t_sdl_manange *s);
void				check_valid_map3(t_sdl_manange *s);
void				ololo(t_sdl_manange *s);
int					is_sprite(int n);
int					is_move(int n);
int					is_wall(int n);
#endif

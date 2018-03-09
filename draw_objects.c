#include "woof.h"

void	sprite_line(t_sdl_manange *s, int x)
{
    t_obj   o;

	o.sp_x = s->map->m_x + 0.5 - s->map->ppos_x;
	o.sp_y = s->map->m_y + 0.5 - s->map->ppos_y;
	o.inv_det = 1.0 / (s->map->plane_x * s->map->dir_y - s->map->dir_x * s->map->plane_y);
	o.tr_x = o.inv_det * (s->map->dir_y * o.sp_x - s->map->dir_x * o.sp_y);
	o.tr_y = o.inv_det * (-s->map->plane_y * o.sp_x + s->map->plane_x * o.sp_y);
	o.sprt_h = abs((int)(HEIGHT / (o.tr_y)));
	o.start_y = -o.sprt_h / 2 + HEIGHT / 2;
	o.start_x = o.sprt_h / 2 + HEIGHT / 2;
	o.start_x = o.start_x >= HEIGHT ? HEIGHT - 1 : o.start_x;
	o.start_y = o.start_y < 0 ? 0 : o.start_y;
	//sprite_line(m, transf, draw_se, x);

///////////////
	o.texture_x = (int)(256 * (s->map->x - (-abs((int)(HEIGHT / (o.tr_y))) / 2 + (int)((s->win_surface->w / 2)
		* (1 + o.tr_x / o.tr_y)))) * s->im_surf[7]->w / abs((int)(HEIGHT / (o.tr_y)))) / 256; // 7 is harcoded
	int y = o.start_y - 1;
	s->map->buffer = (unsigned int *)s->win_surface->pixels + o.start_y * WIDTH + x;
	while (++y < o.start_x)
	{
		int texy;
		texy = (((y * 2 - HEIGHT + o.sprt_h) * s->im_surf[7]->h) / o.sprt_h) / 2;
		if (!*s->map->buffer && o.texture_x >= 0 && texy >= 0 && o.texture_x < s->im_surf[7]->w && texy < s->im_surf[7]->w)
			*s->map->buffer = ((unsigned int*)s->im_surf[7]->pixels)[s->im_surf[7]->w * texy + o.texture_x] & 0xFFFFFF;
		s->map->buffer += WIDTH;
	}
}

// void	draw_sprite()
// {

// }
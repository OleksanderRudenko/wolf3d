#include "woof.h"

void	get_image(t_wolf *one)
{
	one->mal = (t_put_image *)malloc(sizeof(t_put_image));
	one->mal->d_pic = mlx_new_image(one->mlx, WIDTH, HEIGHT);
	one->mal->pic = mlx_get_data_addr(one->mal->d_pic, &one->mal->bpp, &one->mal->s_l, &one->mal->end);
	one->mal->bpp /= 8;
	one->mal->color = mlx_get_color_value(one->mlx, 0xffff);
}

// void pixel_image(t_wolf *one, int x, int y, int color)
// {
//     // one->mal->pic[(y * WIDTH + x) * 4 ] = (color & 0xFF0000) >> 16;
//     // one->mal->pic[(y * WIDTH + x) * 4 + 1] = (color & 0xFF00) >> 8;
//     // one->mal->pic[(y * WIDTH + x) * 4 + 2] =(color & 0xFF);

// 	one->mal->pic[(y * WIDTH + x) * 4 ] = one->textur[0].lll[4 * ()];
//     one->mal->pic[(y * WIDTH + x) * 4 + 1] = (color & 0xFF00) >> 8;
//     one->mal->pic[(y * WIDTH + x) * 4 + 2] = (color & 0xFF);
// }

// void	part2(t_wolf *one, t_im *s)
// {
// 	int	i = 1;

// 	s->d = (s->dx << 1) - s->dy;
// 	s->d1 = s->dx << 1;
// 	s->d2 = (s->dx - s->dy) << 1;
// 	s->y = s->y0 + s->sy;
// 	s->x = s->x0;

// 	while(i <= s->dy)
// 	{
// 		pixel_image(one, s->x, s->y, s->color);
// 		if (s->d > 0)
// 		{
// 			s->d += s->d2;
// 			s->x +=s->sx;
// 		}
// 		else
// 			s->d += s->d2;
// 		i++;
// 		s->y += s->sy;
// 	}
// }

// void ar_line(t_wolf *one, t_im *s)
// {
// 	s->dx = abs(s->x1 - s->x0);
// 	s->dy = abs(s->y1 - s->y0);
// 	s->sx = 0;
// 	s->sy = s->y1 >= s->y0 ? 1 : -1;

// 	part2(one, s);
// 	mlx_put_image_to_window(one->mlx, one->win, one->mal->d_pic, 0, 0);
// }
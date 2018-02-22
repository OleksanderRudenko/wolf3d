#include "woof.h"

void	get_image(t_wolf *one)
{
	one->mal = (t_put_image *)malloc(sizeof(t_put_image));
	one->mal->d_pic = mlx_new_image(one->mlx, WIDTH, HEIGHT);
	one->mal->pic = mlx_get_data_addr(one->mal->d_pic, &one->mal->bpp, &one->mal->s_l, &one->mal->end);
	one->mal->bpp /= 8;
	one->mal->color = mlx_get_color_value(one->mlx, 0xffff);
}

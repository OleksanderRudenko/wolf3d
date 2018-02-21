#include "woof.h"

void get_textures(t_wolf *one)
{
one->textur = (t_texures *)malloc(sizeof(t_texures) * NUM_TEXTURES);
one->textur[0].file =  mlx_xpm_file_to_image(one->mlx, "pic/greystone.xpm", &one->textur->width, &one->textur->height);
one->textur[0].lll = mlx_get_data_addr(one->textur[0].file, &one->textur[0].bpp,
							&one->textur[0].s_l, &one->textur[0].end);


one->textur[1].file =  mlx_xpm_file_to_image(one->mlx, "pic/redbrick.xpm", &one->textur->width, &one->textur->height);
one->textur[1].lll = mlx_get_data_addr(one->textur[1].file, &one->textur[1].bpp,
							&one->textur[1].s_l, &one->textur[1].end);

one->textur[2].file =  mlx_xpm_file_to_image(one->mlx, "pic/bluestone.xpm", &one->textur->width, &one->textur->height);
one->textur[2].lll = mlx_get_data_addr(one->textur[2].file, &one->textur[2].bpp,
							&one->textur[2].s_l, &one->textur[2].end);

one->textur[3].file =  mlx_xpm_file_to_image(one->mlx, "pic/colorstone.xpm", &one->textur->width, &one->textur->height);
one->textur[3].lll = mlx_get_data_addr(one->textur[3].file, &one->textur[3].bpp,
							&one->textur[3].s_l, &one->textur[3].end);

one->textur[4].file =  mlx_xpm_file_to_image(one->mlx, "pic/mossy.xpm", &one->textur->width, &one->textur->height);
one->textur[4].lll = mlx_get_data_addr(one->textur[4].file, &one->textur[4].bpp,
							&one->textur[4].s_l, &one->textur[4].end);
}
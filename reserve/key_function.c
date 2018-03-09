#include "woof.h"

void    key_up(t_sdl_manange *s)
{
    if(s->floor[(int)(s->map->ppos_x + s->map->dir_x * s->map->mv_speed)][(int)(s->map->ppos_y)] == 0)
    {
        s->map->ppos_x += s->map->dir_x * s->map->mv_speed;
    }
    if(s->floor[(int)(s->map->ppos_x)][(int)(s->map->ppos_y + s->map->dir_y * s->map->mv_speed)] == 0)
    {
        s->map->ppos_y += s->map->dir_y * s->map->mv_speed;
    }
}

void    key_down(t_sdl_manange *s)
{
    if(s->floor[(int)(s->map->ppos_x + s->map->dir_x * s->map->mv_speed)][(int)(s->map->ppos_y)] == 0)
    {
        s->map->ppos_x -= s->map->dir_x * s->map->mv_speed;
    }
    if(s->floor[(int)(s->map->ppos_x)][(int)(s->map->ppos_y + s->map->dir_y * s->map->mv_speed)] == 0)
    {
        s->map->ppos_y -= s->map->dir_y * s->map->mv_speed;
    }
}

void    key_right(t_sdl_manange *s)
{
    double oldDirX = s->map->dir_x;
    s->map->dir_x = s->map->dir_x * cosf(-s->map->rot_speed) - s->map->dir_y * sinf(-s->map->rot_speed);
    s->map->dir_y = oldDirX * sinf(-s->map->rot_speed) + s->map->dir_y * cosf(-s->map->rot_speed);
    double oldPlaneX = s->map->pangle_x;
    s->map->pangle_x = s->map->pangle_x * cosf(-s->map->rot_speed) - s->map->pangle_y * sinf(-s->map->rot_speed);
    s->map->pangle_y = oldPlaneX * sinf(-s->map->rot_speed) + s->map->pangle_y * cosf(-s->map->rot_speed);
}

void    key_left(t_sdl_manange *s)
{
    double oldDirX = s->map->dir_x;
    s->map->dir_x = s->map->dir_x * cos(s->map->rot_speed) - s->map->dir_y * sin(s->map->rot_speed);
    s->map->dir_y = oldDirX * sin(s->map->rot_speed) + s->map->dir_y * cos(s->map->rot_speed);
    double oldPlaneX = s->map->pangle_x;
    s->map->pangle_x = s->map->pangle_x * cos(s->map->rot_speed) - s->map->pangle_y * sin(s->map->rot_speed);
    s->map->pangle_y = oldPlaneX * sin(s->map->rot_speed) + s->map->pangle_y * cos(s->map->rot_speed);
}
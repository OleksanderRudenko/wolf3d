#include "woof.h"

void    maluy_pidlogu_ta_stelu(t_sdl_manange *s)
{
    double floorXWall, floorYWall; //x, y position of the floor texel at the bottom of the wall

      //4 different wall directions possible
      if(s->map->side == 0 && s->map->rd_x > 0)
      {
        floorXWall = s->map->m_x;
        floorYWall = s->map->m_y + s->map->w_x;
      }
      else if(s->map->side == 0 && s->map->rd_x < 0)
      {
        floorXWall = s->map->m_x + 1.0;
        floorYWall = s->map->m_y + s->map->w_x;
      }
      else if(s->map->side == 1 && s->map->rd_y > 0)
      {
        floorXWall = s->map->m_x + s->map->w_x;
        floorYWall = s->map->m_y;
      }
      else
      {
        floorXWall = s->map->m_x + s->map->w_x;
        floorYWall = s->map->m_y + 1.0;
      }

      double distWall, distPlayer, currentDist;

      distWall = s->map->pwd;
      distPlayer = 0.0;

      if (s->map->dr_e < 0) s->map->dr_e = HEIGHT; //becomes < 0 when the integer overflows

      //draw the floor from s->map->dr_e to the bottom of the screen
      for(int y = s->map->dr_e + 1; y < HEIGHT; y++)
      {
        currentDist = HEIGHT / (2.0 * y - HEIGHT); //you could make a small lookup table for this instead

        double weight = (currentDist - distPlayer) / (distWall - distPlayer);

        double currentFloorX = weight * floorXWall + (1.0 - weight) * s->map->ppos_x;
        double currentFloorY = weight * floorYWall + (1.0 - weight) * s->map->ppos_y;

        int floorTexX, floorTexY;
        floorTexX = (int)(currentFloorX * 64) % 64;
        floorTexY = (int)(currentFloorY * 64) % 64;
        if (!*s->map->buffer)
          *s->map->buffer = ((unsigned int *)s->im_surf[5]->pixels)[64 * floorTexY + floorTexX];
        if (!*(s->map->buffer + (HEIGHT -2 * y) * WIDTH) )
          *(s->map->buffer + (HEIGHT -2 * y) * WIDTH) = ((unsigned int *)s->im_surf[6]->pixels)[64 * floorTexY + floorTexX];
        s->map->buffer += WIDTH;
      }
    }
#include "woof.h"

#include "woof.h"

int			key_hook(t_sdl_manange *s)
{
    //move forward if no wall in front of you
    while (SDL_PollEvent(&s->event))
    {
      if (s->event.key.keysym.sym == SDLK_w)
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
      // //move backwards if no wall behind you
      if (s->event.key.keysym.sym == SDLK_s)
      {
        if(s->floor[(int)(s->map->ppos_x - s->map->dir_x * s->map->mv_speed)][(int)(s->map->ppos_y)] == 0)
        {
          s->map->ppos_x -= s->map->dir_x * s->map->mv_speed;
        }
        if(s->floor[(int)(s->map->ppos_x)][(int)(s->map->ppos_y - s->map->dir_y * s->map->mv_speed)] == 0)
        {
          s->map->ppos_y -= s->map->dir_y * s->map->mv_speed;
        }
      }
      // //rotate to the right
      if (s->event.key.keysym.sym == SDLK_d)
      {
        //both camera direction and camera plane must be rotated
        double oldDirX = s->map->dir_x;
        s->map->dir_x = s->map->dir_x * cos(-s->map->rot_speed) - s->map->dir_y * sin(-s->map->rot_speed);
        s->map->dir_y = oldDirX * sin(-s->map->rot_speed) + s->map->dir_y * cos(-s->map->rot_speed);
        double oldPlaneX = s->map->pangle_x;
        s->map->pangle_x = s->map->pangle_x * cos(-s->map->rot_speed) - s->map->pangle_y * sin(-s->map->rot_speed);
        s->map->pangle_y = oldPlaneX * sin(-s->map->rot_speed) + s->map->pangle_y * cos(-s->map->rot_speed);
      }
      // //rotate to the left
      if (s->event.key.keysym.sym == SDLK_a)
      {
        //both camera direction and camera plane must be rotated
        double oldDirX = s->map->dir_x;
        s->map->dir_x = s->map->dir_x * cos(s->map->rot_speed) - s->map->dir_y * sin(s->map->rot_speed);
        s->map->dir_y = oldDirX * sin(s->map->rot_speed) + s->map->dir_y * cos(s->map->rot_speed);
        double oldPlaneX = s->map->pangle_x;
        s->map->pangle_x = s->map->pangle_x * cos(s->map->rot_speed) - s->map->pangle_y * sin(s->map->rot_speed);
        s->map->pangle_y = oldPlaneX * sin(s->map->rot_speed) + s->map->pangle_y * cos(s->map->rot_speed);
      }
    }
     return (0);
}


void  draw_map(t_sdl_manange *s)
{
  int x = 0;

    while (x < WIDTH)
    {
      //calculate ray position and direction
      float RayAngle = 2 * x / (float)(WIDTH)-1; //x-coordinate in camera space //x-coordinate in camera space
      float rayDirX = s->map->dir_x + s->map->pangle_x * RayAngle;
      float rayDirY = s->map->dir_y + s->map->pangle_y * RayAngle;
      //which box of the map we're in
      int mapX = (int)(s->map->ppos_x);
      int mapY = (int)(s->map->ppos_y);

      //length of ray from current position to next x or y-side
      float ray_len_x;
      float ray_len_y;

       //length of ray from one x or y-side to next x or y-side
      float deltaDistX = fabs(1 / rayDirX);
      float deltaDistY = fabs(1 / rayDirY);
      float perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        ray_len_x = (s->map->ppos_x - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        ray_len_x = (mapX + 1.0 - s->map->ppos_x) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        ray_len_y = (s->map->ppos_y - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        ray_len_y = (mapY + 1.0 - s->map->ppos_y) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (ray_len_x < ray_len_y)
        {
          ray_len_x += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          ray_len_y += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
       hit = s->floor[mapX][mapY] > 0 ? 1 : 0;
      }
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if (side == 0)
        perpWallDist = (mapX - s->map->ppos_x + (1 - stepX) / 2) / rayDirX;
      else
        perpWallDist = (mapY - s->map->ppos_y + (1 - stepY) / 2) / rayDirY;

      //Calculate height of line to draw on screen
      int lineHeight = (int)(HEIGHT / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + HEIGHT / 2;
      if (drawStart < 0)
        drawStart = 0;
      int drawEnd = lineHeight / 2 + HEIGHT / 2;
      if (drawEnd >= HEIGHT)
        drawEnd = HEIGHT - 1;

    int n = 0;
      //choose wall color
   	if (s->floor[mapX][mapY] == 1)
			n = 0;
		else if (s->floor[mapX][mapY] == 2)
			n = 1;
		else if (s->floor[mapX][mapY] == 3)
			n = 2;
		else if (s->floor[mapX][mapY] == 4)
			n = 3;
    else if (s->floor[mapX][mapY] == 6)
			n = 4;
		else
			n = 0;
      //give x and y sides different brightness

     double wallX; //where exactly the wall was hit
    if (side == 0)
    {
      wallX = s->map->ppos_y + perpWallDist * rayDirY;
      }
      else
      {
        wallX = s->map->ppos_x + perpWallDist * rayDirX;
      }
      wallX -= floor(wallX);

      //x coordinate on the texture
      int texX = (int)(wallX * (double)(s->im_surf[n]->w));
      if(side == 0 && rayDirX > 0)
        {
          texX = s->im_surf[n]->w - texX - 1;
        };
      if(side == 1 && rayDirY < 0)
      {
        texX = s->im_surf[n]->w - texX - 1;
      };

      int y = drawStart;
     
      int d;
      s->map->buffer = (unsigned int *)s->win_surface->pixels + drawStart * s->win_surface->w + x;
      while (y < drawEnd)
      {
          d = y * 256 - HEIGHT * 128 + lineHeight * 128;
          int texY = ((d * s->im_surf[n]->w / lineHeight) / 256);
          //if (texX >= 0 && texX < s->im_surf[n]->h && texY >= 0 && texY < s->im_surf[n]->w)
            *s->map->buffer = ((unsigned int *)s->im_surf[n]->pixels)[s->im_surf[n]->h * texY + texX];
          s->map->buffer += WIDTH;
          y++;
      }
      x++;
    }
}

void	print_list(t_flist *begin)
{
  t_flist *tmp;
  tmp = begin;
	while (tmp->next != NULL)
	{
		ft_putendl(tmp->line);
		tmp = tmp->next;
	}
}

int		main(int argc, char **argv)
{
  t_sdl_manange wolf;
  wolf.begin = read_file(argv[1]);
  print_list(wolf.begin);
  count_symbols(wolf.begin);

  SDL_Init(SDL_INIT_EVERYTHING);
  init_values(&wolf);
  load_textures(&wolf);
  wolf.floor = init_floor(&wolf);
  
  wolf.win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
  wolf.win_surface = SDL_GetWindowSurface(wolf.win);
  while (1)
  {
    if (SDL_PollEvent(&wolf.event))
    {
      if (SDL_QUIT == wolf.event.type || wolf.event.key.keysym.sym == SDLK_ESCAPE)
        break;
    }
    ft_bzero(wolf.win_surface->pixels, WIDTH * HEIGHT * 4);
    key_hook(&wolf);
    draw_map(&wolf);
    SDL_UpdateWindowSurface(wolf.win);
  }
  SDL_DestroyWindow(wolf.win);
	return (0);
}

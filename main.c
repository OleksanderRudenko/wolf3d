#include "woof.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int			mouse_hook(int key, int x, int y, t_wolf *one)
{
  printf("x: %d y: %d \n",x, y);
  return (0);
}

int			key_hook(int key, t_wolf *one)
{
	printf("%d\n",key);
	if (key == 65307)
		exit(0);
//    ft_bzero(one->mal->pic, WIDTH * HEIGHT * one->mal->bpp);
//    mlx_clear_window(one->mlx, one->win);
//    float moveSpeed = 0.5; //the constant value is in squares/second
//     float rotSpeed = 0.2; //the constant value is in radians/second
//     //move forward if no wall in front of you
//     if (key == KEY_UP)
//     {
//       if(worldMap[(int)(one->map->ppos_x + one->map->dir_x * moveSpeed)][(int)(one->map->ppos_y)] == 0)
//       {
//         one->map->ppos_x += one->map->dir_x * moveSpeed;
//       }
//       if(worldMap[(int)(one->map->ppos_x)][(int)(one->map->ppos_y + one->map->dir_y * moveSpeed)] == 0)
//       {
//         one->map->ppos_y += one->map->dir_y * moveSpeed;
//       }
//       draw_map(one);
//     }
//     // //move backwards if no wall behind you
//     if (key == KEY_DOWN)
//     {
//       if(worldMap[(int)(one->map->ppos_x - one->map->dir_x * moveSpeed)][(int)(one->map->ppos_y)] == 0)
//       {
//         one->map->ppos_x -= one->map->dir_x * moveSpeed;
//       }
//       if(worldMap[(int)(one->map->ppos_x)][(int)(one->map->ppos_y - one->map->dir_y * moveSpeed)] == 0)
//       {
//         one->map->ppos_y -= one->map->dir_y * moveSpeed;
//       }
//       draw_map(one);
//     }
//     // //rotate to the right
//     if (key == KEY_RIGHT)
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = one->map->dir_x;
//       one->map->dir_x = one->map->dir_x * cos(-rotSpeed) - one->map->dir_y * sin(-rotSpeed);
//       one->map->dir_y = oldDirX * sin(-rotSpeed) + one->map->dir_y * cos(-rotSpeed);
//       double oldPlaneX = one->map->plane_x;
//       one->map->plane_x = one->map->plane_x * cos(-rotSpeed) - one->map->plane_y * sin(-rotSpeed);
//       one->map->plane_y = oldPlaneX * sin(-rotSpeed) + one->map->plane_y * cos(-rotSpeed);
//       draw_map(one);
//     }
//     // //rotate to the left
//     if (key == KEY_LEFT)
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = one->map->dir_x;
//       one->map->dir_x = one->map->dir_x * cos(rotSpeed) - one->map->dir_y * sin(rotSpeed);
//       one->map->dir_y = oldDirX * sin(rotSpeed) + one->map->dir_y * cos(rotSpeed);
//       double oldPlaneX = one->map->plane_x;
//       one->map->plane_x = one->map->plane_x * cos(rotSpeed) - one->map->plane_y * sin(rotSpeed);
//       one->map->plane_y = oldPlaneX * sin(rotSpeed) + one->map->plane_y * cos(rotSpeed);
//       draw_map(one);
//     }
     return (0);
 }

void  draw_map(t_wolf *one, t_woof *s)
{
  int x = 0;
  unsigned int *buffer;
  
    while (x < WIDTH)
    {
      //calculate ray position and direction
      float cameraX = 2 * x / (float)(WIDTH) - 1; //x-coordinate in camera space
      float rayDirX = one->map->dir_x + one->map->plane_x * cameraX;
      float rayDirY = one->map->dir_y + one->map->plane_y * cameraX;
      
      //which box of the map we're in
      int mapX = (int)(one->map->ppos_x);
      int mapY = (int)(one->map->ppos_y);

      //length of ray from current position to next x or y-side
      float sideDistX;
      float sideDistY;

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
        sideDistX = (one->map->ppos_x - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - one->map->ppos_x) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (one->map->ppos_y - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - one->map->ppos_y) * deltaDistY;
      }
      
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0)
        {
          hit = 1;
        }
      }
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if (side == 0)
        perpWallDist = (mapX - one->map->ppos_x + (1 - stepX) / 2) / rayDirX;
      else
        perpWallDist = (mapY - one->map->ppos_y + (1 - stepY) / 2) / rayDirY;

      
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
   	if (worldMap[mapX][mapY] == 1)
			n = 0;
		else if (worldMap[mapX][mapY] == 2)
			n = 1;
		else if (worldMap[mapX][mapY] == 3)
			n = 2;
		else if (worldMap[mapX][mapY] == 4)
			n = 3;
    else if (worldMap[mapX][mapY] == 6)
			n = 4;
		else
			n = 0;
      //give x and y sides different brightness


         double wallX; //where exactly the wall was hit
      if (side == 0)
      {
        wallX = one->map->ppos_y + perpWallDist * rayDirY;
      }
      else           
      {
        wallX = one->map->ppos_x + perpWallDist * rayDirX;
      }
      wallX -= floor(wallX);

      int texX = (int)(wallX * (double)(TEXTURE_W));
      if(side == 0 && rayDirX > 0)
        {
          texX = TEXTURE_W - texX - 1;
        };
      if(side == 1 && rayDirY < 0)
      {
        texX = TEXTURE_W - texX - 1;
      };

      int y = drawStart;
     
      int d;
      buffer = (unsigned int *)s->im_surf->pixels + drawStart * s->im_surf->w + x;
      while (y < drawEnd)
      {
          d = y * 256 - HEIGHT * 128 + lineHeight * 128;
          int texY = ((d * TEXTURE_W / lineHeight) / 256);
          // one->mal->pic[4 * (WIDTH * y + x)] = one->textur[n].lll[(4 * (TEXTURE_W * texY + texX))];
          // one->mal->pic[(4 * (WIDTH * y + x))+1] = one->textur[n].lll[(4 * (TEXTURE_W * texY + texX))+1];
          // one->mal->pic[(4 * (WIDTH * y + x))+2] = one->textur[n].lll[(4 * (TEXTURE_W * texY + texX))+2];
          //surf->pixels = (unsigned int *)one->textur[n].lll[(4 * (TEXTURE_W * texY + texX))];
          buffer = &((unsigned int *)s->im_surf->pixels)[s->im_surf->h * texY + texX];
          buffer += WIDTH;
          y++;
      }
      x++;
    }
    //SDL_BlitSurface(s->im_surf, NULL, s->window_surface, NULL);
    //mlx_put_image_to_window(one->mlx, one->win, one->mal->d_pic, 0, 0);
}

void  init_values(t_wolf *one)
{
  one->map = (t_map *)malloc(sizeof(t_map));

  one->map->ppos_x = 15;
  one->map->ppos_y = 12;
  one->map->dir_x = -1;
  one->map->dir_y = 0;
  one->map->plane_x = 0;
  one->map->plane_y = 0.66;
}

// int		main()
// {
// 	// SDL_Init(SDL_INIT_EVERYTHING);
// 	// //SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
// 	// SDL_Window *win = 0;
// 	// SDL_Renderer *ren = 0;
// 	// win = SDL_CreateWindow("MAIN", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED ,640, 480, 0);
//   t_wolf  one;
//   one.mlx = mlx_init();
//   one.win = mlx_new_window(one.mlx, WIDTH, HEIGHT, "wolf");
//   get_image(&one);
//   get_textures(&one);
//   init_values(&one);
//   draw_map(&one);

//   mlx_hook(one.win,2,5,key_hook, &one);
//   mlx_mouse_hook(one.win, mouse_hook, &one);
// 	mlx_loop(one.mlx);
// 	return (0);
// }



SDL_Surface *load_surf(char *filepath)
{
  SDL_Surface *surf = SDL_LoadBMP(filepath);
  if (surf == NULL)
  {
    printf("%s\n", SDL_GetError());
  }
  return (surf);
}


int main (int argc, char **argv)
{

t_woof one;
t_wolf two;

   two.mlx = mlx_init();
   get_image(&two);
   get_textures(&two);
   init_values(&two);

  SDL_Init(SDL_INIT_VIDEO);


    one.win = SDL_CreateWindow("LOL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);

   one.window_surface = SDL_GetWindowSurface(one.win);
    one.im_surf = load_surf("pic/redbrick.bmp");
    SDL_Event event;
    draw_map(&two, &one);

    while (1)
    {
      if (SDL_PollEvent(&event))
      {
        if (SDL_QUIT == event.type || event.key.keysym.sym == SDLK_ESCAPE)
        {
          break;
        }
      }
      draw_map(&two, &one);
     SDL_UpdateWindowSurface(one.win);
    }
    
    return (0);
}
/*
** load.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 23:40:44 2013 vincent colliot
** Last update Mon Jun  3 16:02:15 2013 vincent colliot
*/

#include "screen.h"
#include "zbuffer.h"

static t_3d	ray_adapt(t_3d f, t_2i pix)
{
  t_3d ray;
  t_2d i;

  i.x = ((pix.x - (SCREEN_SIZE_X / 2.0))) / 100.0;
  i.y = -((pix.y - (SCREEN_SIZE_Y / 2.0))) / 100.0;
  ray.x = i.x * cosf(f.y) * cosf(f.z)
    + i.y * (cosf(f.x) * (-sinf(f.z)) + sinf(f.x) * sinf(f.y) * cosf(f.z))
    + FOV * (sinf(f.x) * sinf(f.z) + cosf(f.x) * sinf(f.y) * cosf(f.z));
  ray.y = i.x * (cosf(f.y) * sinf(f.z))
    + i.y * (cosf(f.x) * cosf(f.z) + sinf(f.x) * sinf(f.y) * sinf(f.z))
    + FOV * (-sinf(f.x) * cosf(f.z) + cosf(f.x) * sinf(f.y) * sinf(f.z));
  ray.z = i.x * (-sin(f.y))
    + i.y * (sinf(f.x) * cosf(f.y))
    + FOV * (cosf(f.x)) * cosf(f.y);
  return (ray);
}

void	load_img(t_screen *screen, CLASS_DISPLAY *d)
{
  t_color	color;
  t_2i		pix;

  pix.y = 0;
  while (pix.y < SCREEN_SIZE_Y)
    {
      pix.x = 0;
      while (pix.x < SCREEN_SIZE_X)
	{
	  color = zbuffering(d, d->objects,
			       convert_norm(ray_adapt(d->eye->focus, pix)),
			       1);
	  pix_it(screen, pix, color);
	  pix.x += d->eye->scale;
	}
      pix.y += d->eye->scale;
    }
}

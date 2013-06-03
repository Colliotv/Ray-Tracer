/*
** put_pixel.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 23:49:00 2013 vincent colliot
** Last update Mon Jun  3 17:58:04 2013 vincent colliot
*/

#include "screen.h"

static inline void            save(t_image *screen, int x, int y, unsigned int rgb)
{
  size_t           pos;

  pos = (x) * (screen->bpp / 8) + (y) * screen->size_line;
  *(unsigned int*)(screen->stack + pos * sizeof(unsigned char)) = rgb;
}

void            pix_it(t_screen *screen, t_2i pix, t_color color)
{
  save(screen->screensave, pix.x, pix.y,
       mlx_get_color_value(screen->mlx_ptr, color.i));
}

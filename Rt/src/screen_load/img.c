/*
** img.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 23:16:02 2013 vincent colliot
** Last update Mon Jun  3 00:06:04 2013 vincent colliot
*/

#include <mlx.h>
#include <stdlib.h>
#include "screen.h"

void    img_init(t_image *img, t_screen *screen)
{
  int   bpp;
  int   big_E;

  img->img_ptr = mlx_new_image(screen->mlx_ptr, img->width, img->height);
  img->stack = mlx_get_data_addr(img->img_ptr, &bpp, &(img->size_line), &big_E);
  img->bpp = bpp;
  img->window = screen;
  img->big_E = big_E;
}


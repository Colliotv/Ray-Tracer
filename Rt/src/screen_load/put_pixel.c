/*
** put_pixel.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 23:49:00 2013 vincent colliot
** Last update Tue Jun  4 20:42:06 2013 quentin cloarec
*/

#include "filtre.h"
#include "screen.h"

static inline void            save(t_image *screen, int x, int y, unsigned int rgb)
{
  size_t           pos;

  pos = (x) * (screen->bpp / 8) + (y) * screen->size_line;
  *(unsigned int*)(screen->stack + pos * sizeof(unsigned char)) = rgb;
}

/*
 * ¤¤¤¤
 *pour l'aliasing penser a faire une boucle de remplissage...
 * ¤¤¤¤
*/

void            pix_it(t_screen *screen, t_2i pix, t_color color)
{
  //  color = filtre(color);
  save(screen->screensave, pix.x, pix.y,
       mlx_get_color_value(screen->mlx_ptr, color.i));
}

/*
 * ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤
 * soit get_pix(screen (or &screen, (coord.x.y), NULL (ou ptr sur un t_color))
 * si color!=NULL préférez cette syntax pour l'opti du bordel-->(void)get_pix(lalalala....)
 * ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤
 */


static t_color	get_save(t_image *screen, int x, int y)
{
  t_color	color;
  size_t	pos;

  pos = (x) * (screen->bpp / 8) + (y) * screen->size_line;
  color.i =
    *(unsigned int*)(screen->stack + pos * sizeof(unsigned char));
  return (color);
}

t_color		get_pix(t_screen *screen, t_2i pix, t_color *color)
{
  t_color	get;

  get = get_save(screen->screensave, pix.x, pix.y);
  if (color)
    *color = get;
  return (get);
}

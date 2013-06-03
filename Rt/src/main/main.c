/*
** main.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 16:29:41 2013 vincent colliot
** Last update Mon Jun  3 23:29:43 2013 vincent colliot
*/

#include <mlx.h>
#include "display.h"
#include "token.h"
#include "screen.h"
#include "lerror.h"

int		nfn(t_screen *screen)
{
  IMG_PUT(screen->mlx_ptr, screen->win_ptr,
	  ((t_image*)(screen->screensave))->img_ptr, 0, 0);
  return (0);
}

int		move(int key)
{
  if (key == 65307)
    exit(-1);
  return (0);
}

void		mlx_hook_init(t_screen screen)
{
  mlx_key_hook(screen.win_ptr, move, NULL);
  mlx_expose_hook(screen.win_ptr, nfn, &screen);
}

int	main(int ac, char **av)
{
  t_screen	screen;
  CLASS_DISPLAY	d;

  if ((screen.mlx_ptr = mlx_init()) == NULL)
    lerror(USAGE);
  xml_scan(&d, ac, av);
  if (!d.eye)
    lerror(USAGE);
  screen_it(&screen, "-----> Rt...WHAT DA F****? <-----",
            SCREEN_SIZE_X, SCREEN_SIZE_Y);
  img_init(screen.screensave, &screen);
  load_img(&screen, &d);
  mlx_hook_init(screen);
  IMG_PUT(screen.mlx_ptr, screen.win_ptr,
	  ((t_image*)(screen.screensave))->img_ptr, 0, 0);
  mlx_loop(screen.mlx_ptr);
  return (0);
}

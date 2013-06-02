/*
** main.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 16:29:41 2013 vincent colliot
** Last update Sun Jun  2 23:40:16 2013 vincent colliot
*/

#include "display.h"
#include "token.h"
#include "screen.h"
#include "lerror.h"

int	main(int ac, char **av)
{
  t_screen	screen;
  CLASS_DISPLAY	d;

  if ((screen.mlx_ptr = mlx_init()) == NULL)
    lerror(USAGE);
  xml_scan(&d, ac, av);
  screen_it(&screen, "-----> Rt...WHAT DA F****? <-----",
            SCREEN_SIZE_X, SCREEN_SIZE_Y);
  img_init(screen.screensave, &screen);
  load_img(&screen, &d);
  return (0);
}

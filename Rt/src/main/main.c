/*
** main.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 16:29:41 2013 vincent colliot
** Last update Wed Jun  5 17:22:11 2013 vincent colliot
*/

#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <strings.h>
#include <mlx.h>
#include "display.h"
#include "token.h"
#include "screen.h"
#include "lerror.h"
#include "select.h"

int		nfn(t_screen *screen)
{
  IMG_PUT(screen->mlx_ptr, screen->win_ptr,
	  ((t_image*)(screen->screensave))->img_ptr, 0, 0);
  return (0);
}

int		move(int key, void *select)
{
  t_screen	*screen;
  CLASS_DISPLAY	*d;

  d = ((t_select*)select)->d;
  screen = ((t_select*)select)->screen;
  if (key == EXIT)
    exit(-1);
  else if (key == UP)
    d->eye->position.y += 1;
  else if (key == DOWN)
    d->eye->position.y -= 1;
  else if (key == LEFT)
    d->eye->position.x += 1;
  else if (key == RIGHT)
    d->eye->position.x -= 1;
  return (-1);
  bzero(((t_image*)(screen->screensave))->stack, sizeof(char)
	* (SCREEN_SIZE_X * (((t_image*)(screen->screensave))->bpp / 8)
	   + SCREEN_SIZE_Y * (((t_image*)(screen->screensave))->size_line)));
  load_img(screen, d);
  IMG_PUT(screen->mlx_ptr, screen->win_ptr,
  	  ((t_image*)(screen->screensave))->img_ptr, 0, 0);
  return (0);
}

void		mlx_hook_init(t_screen *screen, CLASS_DISPLAY *d,
			      t_select *select)
{
  select->d = d;
  select->screen = screen;
  mlx_key_hook(screen->win_ptr, move, select);
  mlx_expose_hook(screen->win_ptr, nfn, screen);
}

int	main(int ac, char **av)
{
  t_select	select;
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
  srandom(time(0) * getpid());
  load_img(&screen, &d);
  mlx_hook_init(&screen, &d, &select);
  printf("finished\n");
  IMG_PUT(screen.mlx_ptr, screen.win_ptr,
	  ((t_image*)(screen.screensave))->img_ptr, 0, 0);
  mlx_loop(screen.mlx_ptr);
  return (0);
}

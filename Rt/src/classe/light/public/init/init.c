/*
** init.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display/public/scan
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 17:17:33 2013 vincent colliot
** Last update Fri May 31 02:33:41 2013 vincent colliot
*/

#include "light.h"
#include "string.h"
#include "xmalloc.h"
#include "display.h"

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (2 + 1));
  (tab[0]).call = light_pos;
  (tab[0]).name = "position";
  (tab[1]).call = light_color;
  (tab[1]).name = "color";
  (tab[2]).call = NULL;
  (tab[2]).name = NULL;
  return (tab);
}

void	light_init(void *light, void *d)
{
  ((CLASS_LIGHT*)light)->scan = ini_scan();
  ((CLASS_LIGHT*)light)->next = ((CLASS_DISPLAY*)d)->lights;
  ((CLASS_DISPLAY*)d)->lights = light;
}

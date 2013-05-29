/*
** init.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display/public/scan
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 17:17:33 2013 vincent colliot
** Last update Tue May 28 01:01:24 2013 vincent colliot
*/

#include "light.h"

static t_scan	*ini_scan(void)
{
  t_scan_token	*tab;

  tab = xmalloc(sizeof(*tab) * (TO_DEFINE + 1));
  tab[0].call = light_pos;
  tab[0].div = "position"
  tab[1].call = light_color;
  tab[1].div = "color"
  tab[2].div = NULL;
  tab[2].call = NULL;
}

void	light_init(CLASS_LIGHT *light, CLASS_DISPLAY *d);
{
  light->scan = ini_scan;
  light->next = d->light;
  d->light = light;
}

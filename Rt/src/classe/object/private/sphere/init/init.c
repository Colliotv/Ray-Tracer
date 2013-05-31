/*
** init.c<7> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 13:33:06 2013 vincent colliot
** Last update Fri May 31 15:03:36 2013 vincent colliot
*/

#include "object.h"
#include "xmalloc.h"

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (3 + 1));
  (tab[0]).call = sphere_pos;
  (tab[0]).name = "position";
  (tab[1]).call = sphere_color;
  (tab[1]).name = "color";
  (tab[1]).call = sphere_rayon;
  (tab[1]).name = "rayon";//<--- serait bien de faire des defines;;;;plus tard
  (tab[2]).call = NULL;
  (tab[2]).name = NULL;
  return (tab);
}

void	sphere_init(void *o, t_token *token)
{
  t_sphere	*s;

  (void)token;
  s = xmalloc(sizeof(*s));
  s->scan = ini_scan();
  s->collide = NULL;
  s->normal = NULL;
  *((t_sphere**)o) = s;
}

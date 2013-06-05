/*
** init.c<4> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 13:19:02 2013 vincent colliot
** Last update Wed Jun  5 12:44:24 2013 vincent colliot
*/

#include <strings.h>
#include "object.h"
#include "xmalloc.h"

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (6 + 1));
  (tab[0]).call = plan_color;
  (tab[0]).name = COLOR;
  (tab[1]).call = plan_focus;
  (tab[1]).name = FOCUS;//<--- serait bien de faire des defines;;;;plus tard
  (tab[2]).call = plan_high;
  (tab[2]).name = "high";
  (tab[3]).name = SHINING;
  (tab[3]).call = object_shining;
  (tab[4]).call = object_alpha;
  (tab[4]).name = ALPHA;
  (tab[5]).call = object_gamma;
  (tab[5]).name = GAMMA;
  (tab[6]).call = NULL;
  (tab[6]).name = NULL;
  return (tab);
}

void	plan_init(void *o, t_token *token)
{
  t_plan	*s;

  (void)token;
  s = xmalloc(sizeof(*s));
  bzero(s, sizeof(*s));
  s->scan = ini_scan();
  s->collide = collide_plan;
  s->normal = normal_plan;
  *((t_plan**)o) = s;
}

/*
** init.c<4> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 13:19:02 2013 vincent colliot
** Last update Mon Jun  3 01:19:31 2013 vincent colliot
*/

#include "object.h"
#include "xmalloc.h"

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (4 + 1));
  (tab[0]).call = plan_color;
  (tab[0]).name = COLOR;
  (tab[1]).call = plan_focus;
  (tab[1]).name = FOCUS;//<--- serait bien de faire des defines;;;;plus tard
  (tab[2]).call = plan_high;
  (tab[2]).name = "high";
  (tab[3]).call = NULL;
  (tab[3]).name = NULL;
  return (tab);
}

void	plan_init(void *o, t_token *token)
{
  t_plan	*s;

  (void)token;
  s = xmalloc(sizeof(*s));
  s->scan = ini_scan();
  s->collide = collide_plan;
  s->normal = NULL;
  *((t_plan**)o) = s;
}

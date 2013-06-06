/*
** normal.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 01:10:41 2013 vincent colliot
** Last update Thu Jun  6 02:35:25 2013 vincent colliot
*/

#include "object.h"
#include "dim.h"

t_3d	normal_plan(void *plan, t_3d collide, t_collide *v)
{
  t_3d	narmol;

  (void)collide;
  v->n_spec = 1;
  narmol = ((t_plan*)plan)->focus;
  return (narmol);
}

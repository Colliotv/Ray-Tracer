/*
** normal.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 01:10:41 2013 vincent colliot
** Last update Mon Jun  3 01:48:31 2013 vincent colliot
*/

#include "object.h"
#include "dim.h"

t_3d	normal_plan(void *plan, t_3d collide)
{
  (void)collide;
  return (((t_plan*)plan)->focus);
}

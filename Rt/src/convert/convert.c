/*
** convert.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 15:40:03 2013 vincent colliot
** Last update Sun Jun  2 03:04:28 2013 vincent colliot
*/

#include "math.h"
#include "dim.h"

t_3d	convert_focus(t_3d c)
{
  t_3d	k;
  t_3d	focus;

  k.x = 0;
  k.y = 1;
  k.z = 0;
  focus.x = k.x * cos(c.y) * cos(c.z)
    + k.y * (cos(c.x) * (-sin(c.z)) + sin(c.x) * sin(c.y) * cos(c.z))
    + k.z * (sin(c.x) * sin(c.z) + cos(c.x) * sin(c.y) * cos(c.z));
  focus.y = k.x * (cos(c.y) * sin(c.z))
    + k.y * (cos(c.x) * cos(c.z) + sin(c.x) * sin(c.y) * sin(c.z))
    + k.z * (-sin(c.x) * cos(c.z) + cos(c.x) * sin(c.y) * sin(c.z));
  focus.z = k.x * (-sin(c.y))
    + k.y * (sin(c.x) * cos(c.y))
    + k.z * (cos(c.x)) * cos(c.y);
  return (focus);
}

t_3d	dist_convert(t_3d pos, t_3d vect, double n)
{
  t_3d	dist;

  dist.x = pos.x + vect.x * n;
  dist.y = pos.y + vect.y * n;
  dist.z = pos.z + vect.z * n;
  return (dist);
}

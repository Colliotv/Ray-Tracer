/*
** convert.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 15:40:03 2013 vincent colliot
** Last update Fri May 31 15:48:55 2013 vincent colliot
*/

#include "math.h"
#include "dim.h"

t_3d	convert_focus(t_3d c)
{
  t_3d	focus;

  focus.x = cosf(c.y) * cosf(c.z)
    + (cosf(c.x) * (-sinf(c.z)) + sinf(c.x) * sinf(c.y) * cosf(c.z))
    + (sinf(c.x) * sinf(c.z) + cosf(c.x) * sinf(c.y) * cosf(c.z));
  focus.y = (cosf(c.y) * sinf(c.z))
    + (cosf(c.x) * cosf(c.z) + sinf(c.x) * sinf(c.y) * sinf(c.z))
    + (-sinf(c.x) * cosf(c.z) + cosf(c.x) * sinf(c.y) * sinf(c.z));
  focus.z = (-sin(c.y))
    + (sinf(c.x) * cosf(c.y))
    + (cosf(c.x)) * cosf(c.y);
  return (focus);
}

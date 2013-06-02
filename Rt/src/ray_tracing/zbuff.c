/*
** zbuff.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 00:47:07 2013 vincent colliot
** Last update Mon Jun  3 01:09:56 2013 vincent colliot
*/

#include <strings.h>
#include "display.h"
#include "screen.h"
#include "dim.h"

static BOOL	fill_collide(CLASS_OBJECT *object, t_3d ray, t_3d pos,
			     t_collide *collide)
{
  t_collide	fill;

  bzero(&fill, sizeof(fill));
  if (!object->collide)
    return (FALSE);
  fill.collide = (object->collide)((void*)object, ray, pos, &fill);
  if (fill.defined == 0)
    return (FALSE);
  if ((fill.k)[fill.up_to] < (collide.k)[collide.up_to])
    memcpy(&fill, collide, sizeof(*collide));
  else
    return (FALSE);
  if (!object->normal)
    return (TRUE);
  else
    collid->normal = (object->normal)((void*)object, collide->collide);
  return (TRUE);
}

t_color	zbuffering(CLASS_DISPLAY *d, CLASS_OBJECT *o, t_3d ray)
{
  t_collide	collide;

  bzero(&collide, sizeof(collide));
  while (o)
    {
      if (fill_collide(o, ray, d->eye->position, &collide))
	{

	}
      o = o->next;
    }
}

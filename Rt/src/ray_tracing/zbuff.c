/*
** zbuff.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 00:47:07 2013 vincent colliot
** Last update Mon Jun  3 16:14:50 2013 vincent colliot
*/

#include <strings.h>
#include "display.h"
#include "screen.h"
#include "dim.h"
#include "spot.h"

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
  if ((fill.k)[fill.up_to] < (collide->k)[collide->up_to])
    memcpy(&fill, collide, sizeof(*collide));
  else
    return (FALSE);
  collide->shining = object->shine;
  if (!object->normal)
    return (TRUE);
  else
    collide->normal =
      convert_norm((object->normal)((void*)object, collide->collide));
  return (TRUE);
}

t_color	zbuffering(CLASS_DISPLAY *d, CLASS_OBJECT *object, t_3d ray, double reverb)
{
  t_collide	collide;

  bzero(&collide, sizeof(collide));
  while (object)
    {
      if (fill_collide(object, ray, d->eye->position, &collide))
	{
	  collide.alpha = reverb - object->alpha;
	  collide.gamma = reverb - object->gamma;
	  collide.color = object->get_color(d, (void*)object, collide, ray);
	  collide.color = add_spot_color(collide, d->lights, d->objects);
	}
      object = object->next;
    }
  return (collide.color);
}

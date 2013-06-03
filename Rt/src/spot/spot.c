/*
** spot.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 14:30:25 2013 vincent colliot
** Last update Mon Jun  3 17:33:26 2013 vincent colliot
*/

/*
 * ¤¤¤¤¤¤¤¤¤
 * shuriken!
 * ¤¤¤¤¤¤¤¤¤
**/

#include "display.h"
#include "zbuffer.h"

static t_color	spot_modify(t_collide collide, t_color final, double angle)
{
  t_color	r;

  (r.rgb)[R] = angle * (final.rgb)[R] *(((collide.color).rgb)[R] / 255
					     + collide.shining);
  (r.rgb)[G] = angle * (final.rgb)[B] *(((collide.color).rgb)[G] / 255
					     + collide.shining);
  (r.rgb)[B] = angle * (final.rgb)[B] *(((collide.color).rgb)[B] / 255
					     + collide.shining);
  return (r);
}

t_color	add_spot_color(t_collide collide, CLASS_LIGHT *light, CLASS_OBJECT *object)
{
  t_color	final;

  while (light)
    {
      collide.light = light->position;
      collide.r_light = convert_ray(light->position, collide.collide);
      final = spot_add(collide, light->color, 1, object);
      final = spot_modify(collide, final,
			  convert_cos(convert_ray(light->position,
						  collide.collide),
				      collide.normal));
      collide.color = final;
      light = light->next;
    }
  return (collide.color);
}

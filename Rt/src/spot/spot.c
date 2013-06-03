/*
** spot.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 14:30:25 2013 vincent colliot
** Last update Mon Jun  3 16:12:47 2013 vincent colliot
*/

/*
 * ¤¤¤¤¤¤¤¤¤
 * shuriken!
 * ¤¤¤¤¤¤¤¤¤
**/

#include "display.h"

static t_color	spot_modify(t_collide collide, t_color final, double ct, double angle)
{
  t_color	r;

  (r.rgb)[R] = ct * angle * (final.rgb)[R] *(((collide.color).rgb)[R] / 255
					     + collide.shining);
  (r.rgb)[G] = ct * angle * (final.rgb)[B] *(((collide.color).rgb)[G] / 255
					     + collide.shining);
  (r.rgb)[B] = ct * angle * (final.rgb)[B] *(((collide.color).rgb)[B] / 255
					     + collide.shining);
  return (r);
}

t_color	add_spot_color(t_collide collide, CLASS_LIGHT *light, CLASS_OBJECT *object)
{
  double	ct;
  t_color	final;

  while (light)
    {
      ct = 1;
      final = collide.color;
      final = spot_add(collide, light, object, &ct);
      final = spot_modify(collide, final, ct,
			  convert_cos(convert_ray(light->position,
						  collide.collide),
				      collide.normal));
      collide.color = final;
      light = light->next;
    }
  return (collide.color);
}

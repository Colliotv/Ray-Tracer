/*
** spot.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 14:30:25 2013 vincent colliot
<<<<<<< HEAD
** Last update Tue Jun  4 17:20:43 2013 vincent colliot
=======
** Last update Tue Jun  4 14:05:18 2013 pierre-louis rebours
>>>>>>> 786e49a2cc6941b4bc6ef4031ec3a1fd25a2152e
*/

/*
 * ¤¤¤¤¤¤¤¤¤
 * shuriken!
 * ¤¤¤¤¤¤¤¤¤
**/

#include <strings.h>
#include "display.h"
#include "zbuffer.h"
#include "spot.h"

static double	add_dist(t_collide collide)
{
  t_3d	n;

  return (1);
  n.x = collide.collide.x - collide.light.x;
  n.y = collide.collide.y - collide.light.y;
  n.z = collide.collide.z - collide.light.z;
  return (sqrt(C(n.x) + C(n.y) + C(n.z)));
}

static t_color	spot_modify(t_collide collide, t_color final, double angle)
{
  t_color	r;

  bzero(&r, sizeof(r));
  if (angle <= 0 && collide.n_spec)
    angle = -angle;
  else if (!collide.n_spec && angle <= 0)
    return (r);
  (r.rgb)[R] = angle * (final.rgb)[R] * (((double)((collide.color).rgb)[R]) / 255
					 + collide.shining)
    / add_dist(collide);
  (r.rgb)[G] = angle * (final.rgb)[G] * (((collide.color).rgb)[G] / 255
					 + collide.shining)
    / add_dist(collide);
  (r.rgb)[B] = angle * (final.rgb)[B] * (((collide.color).rgb)[B] / 255
					 + collide.shining)
    / add_dist(collide);
  return (r);
}

static void	add_all_color(t_color c1, int c2[3], int r[3])
{
  (r)[R] = (c1.rgb)[R] + (c2)[R];
  (r)[G] = (c1.rgb)[G] + (c2)[G];
  (r)[B] = (c1.rgb)[B] + (c2)[B];
}

static inline t_color	div_all_color(int c[3], size_t i)
{
  t_color r;

  bzero(&r, sizeof(r));
  if (!i)
    return (r);
  (c)[R] /= i;
  (c)[G] /= i;
  (c)[B] /= i;
  (r.rgb)[R] = c[R];
  (r.rgb)[G] = c[G];
  (r.rgb)[B] = c[B];
  return (r);
}

t_color	add_spot_color(t_collide collide, CLASS_LIGHT *light,
		       CLASS_OBJECT *object, double reverb)
{
  size_t	i;
  int		final[3];
  t_color	cont;

  bzero(&final, sizeof(final));
  i = 0;
  while (light)
    {
      collide.light = light->position;
      collide.r_light = convert_ray(light->position, collide.collide);
      cont = spot_add(collide, light->color, reverb, object);
      cont = spot_modify(collide, cont,
			  convert_cos(convert_ray(light->position,
						  collide.collide),
				      collide.normal));
      (void)add_all_color(cont, final, final);
      light = light->next;
      i++;
    }
  return (div_all_color(final, i));
}

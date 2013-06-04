/*
** normal.c<4> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 01:41:25 2013 vincent colliot
** Last update Tue Jun  4 17:22:32 2013 vincent colliot
*/

#include <strings.h>
#include "object.h"
#include "dim.h"

t_3d	normal_cone(void *cone, t_3d collide, t_collide *v)
{
  t_3d	normal;
  t_3d	narmol;

  bzero(&normal, sizeof(normal));
  (void)v;
  narmol.x = collide.x - ((t_cone*)cone)->position.x;
  narmol.y = collide.y - ((t_cone*)cone)->position.y;
  narmol.z = collide.z - ((t_cone*)cone)->position.z;
  normal.x -= narmol.x - narmol.x * ((t_cone*)cone)->focus.x
    - narmol.x * ((t_cone*)cone)->focus.x * C(tan(((t_cone*)cone)->angle));
  normal.y -= narmol.y - narmol.y * ((t_cone*)cone)->focus.y
    - narmol.y * ((t_cone*)cone)->focus.y * C(tan(((t_cone*)cone)->angle));
  normal.z -= narmol.z - narmol.z * ((t_cone*)cone)->focus.z
    - narmol.z * ((t_cone*)cone)->focus.z * C(tan(((t_cone*)cone)->angle));
  return (normal);
}

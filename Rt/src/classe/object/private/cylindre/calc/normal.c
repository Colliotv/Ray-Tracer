/*
** normal.c<3> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 01:23:44 2013 vincent colliot
** Last update Tue Jun  4 13:58:53 2013 vincent colliot
*/

#include <strings.h>
#include "object.h"
#include "dim.h"

t_3d	normal_cylindre(void *cylindre, t_3d collide, t_collide *v)
{
  t_3d	normal;
  t_3d	narmol;

  bzero(&normal, sizeof(normal));
  (void)v;
  narmol.x = collide.x - ((t_cylindre*)cylindre)->position.x;
  narmol.y = collide.y - ((t_cylindre*)cylindre)->position.y;
  narmol.z = collide.z - ((t_cylindre*)cylindre)->position.z;
  normal.x -= narmol.x - narmol.x * ((t_cylindre*)cylindre)->focus.x;
  normal.y -= narmol.y - narmol.y * ((t_cylindre*)cylindre)->focus.y;
  normal.z -= narmol.z - narmol.z * ((t_cylindre*)cylindre)->focus.z;
  return (normal);
}

/*
** collide.c<3> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 01:41:50 2013 vincent colliot
** Last update Sun Jun  2 02:47:27 2013 vincent colliot
*/

#include "object.h"
#include "dim.h"

static void	init(t_3d *pos, t_3d *focus, double *rayon, t_cone *cone)
{
  *pos = cone->position;
  *focus = cone->focus;
  *rayon = cone->rayon;
}

t_3d	collide_cylindre(void *cylindre, t_3d pos, t_3d r, t_collide *k)
{
  t_3d	 p;
  t_3d	 f;
  double rayon;
  t_3e   D;

  init(&p, &f, &rayon, (t_cone*)cone);
  D.a = C(r.x) + C(r.y) + C(r.z) - C(f.x * r.x + f.y * r.y + f.z * r.z);
  D.b = 2 * (r.x * (pos.x - p.x) + r.y * (pos.y - p.y) + r.y * (pos.y - p.y))
    - 2 * (r.x * f.x + r.y * f.y + r.z * f.z)
    * (f.x * (pos.x - p.x) + f.y * (pos.y - p.y) + f.z * (pos.z - p.z));
  D.c = C(pos.x - p.x) + C(pos.y - p.y) + C(pos.x - p.x) - C(rayon)
    - C(f.x * (pos.x - p.x) + f.y * (pos.y - p.y) + f.z * (pos.z - p.z));
  if ((k->defined = 2 * (C(b) - 4 * a * c > 0)))
    {
      (k->k)[0] = -b + sqrtf(C(b) - 4 * a * c);
      (k->k)[0] = -b - sqrtf(C(b) - 4 * a * c);
      return (collide_arrange(k, pos, r));
    }
  else if ((k->defined = 1 * (C(b) - 4 * a * c == 0)))
    {
      (k->k)[0] = (-b) / (2 * a);
      return (dist_convert(pos, r, (k->k)[0]));
    }
  k->defined = 0;
  return ((t_3d)EXIT_FAILURE);//pos
}

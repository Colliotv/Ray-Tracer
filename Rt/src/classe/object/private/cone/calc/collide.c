/*
** collide.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Jun  1 23:42:08 2013 vincent colliot
** Last update Sun Jun  2 02:54:20 2013 vincent colliot
*/

static void	init(t_3d *pos, t_3d *focus, double *angle, t_cone *cone)
{
  *pos = cone->position;
  *focus = cone->focus;
  *angle = cone->angle;
}

t_3d	collide_cone(void *cone, t_3d pos, t_3d r, t_collide *k)
{
  t_3d	 p;
  t_3d	 focus;
  double angle;
  t_3e   D;

  init(&p, &focus, &angle, (t_cone*)cone);
  D.a = C(r.x) + C(r.y) + C(r.z) - C(f.x * r.x + f.y * r.y + f.z * r.z)
    - C(f.x * r.x + f.y * r.y + f.z * r.z) * C(tan(angle));
  D.b = 2 * (r.x * (pos.x - p.x) + r.y * (pos.y - p.y) + r.y * (pos.y - p.y))
    - 2 * (r.x * f.x + r.y * f.y + r.z * f.z)
    * (f.x * (pos.x - p.x) + f.y * (pos.y - p.y) + f.z * (pos.z - p.z))
    - 2 * (r.x * f.x + r.y * f.y + r.z * f.z) * C(tan(angle))
    * (f.x * (pos.x - p.x) + f.y * (pos.y - p.y) + f.z * (pos.z - p.z));
  D.c = C(pos.x - p.x) + C(pos.y - p.y) + C(pos.x - p.x)
    - C(f.x * (pos.x - p.x) + f.y * (pos.y - p.y) + f.z * (pos.z - p.z))
    - C(tan(angle)) *
    C(f.x * (pos.x - p.x) + f.y * (pos.y - p.y) + f.z * (pos.z - p.z));
  if ((k->defined = 2 * (C(b) - 4 * a * c > 0)))
    {
      (k->k)[0] = -b + sqrtf(C(b) - 4 * a * c);
      (k->k)[0] = -b - sqrtf(C(b) - 4 * a * c);
      return (collide_arrange(k, pos, r));
    }
  else if ((k->defined = 1 * (C(b) - 4 * a * c == 0)))
    return (dist_convert(pos, r, (k->k)[0] = (-b) / (2 * a)));
  return ((t_3d)EXIT_FAILURE);//pos
}

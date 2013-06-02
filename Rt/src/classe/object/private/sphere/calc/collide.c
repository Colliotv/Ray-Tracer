/*
** collide.c<4> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 02:47:48 2013 vincent colliot
** Last update Sun Jun  2 02:53:58 2013 vincent colliot
*/

t_3d	collide_cone(void *sphere, t_3d pos, t_3d r, t_collide *k)
{
  t_3d	p;
  t_3d	D;
  double rayon;

  rayon = (*(t_sphere*)sphere)->rayon;
  p = (*(t_sphere*)sphere)->position;
  D.a = C(r.x) + C(r.y) + C(r.z);
  D.b = 2(r.x * (pos.x - p.x) + r.y * (pos.y - p.y) + r.z * (pos.z - p.z));
  D.c = C(pos.x - p.x) + C(pos.y - p.y) + C(pos.z - p.z);
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

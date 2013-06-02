/*
** normal.c<4> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 01:41:25 2013 vincent colliot
** Last update Mon Jun  3 01:44:54 2013 vincent colliot
*/

t_3d	normal_cone(void *cone, t_3d collide)
{
  t_3d	narmol;

  narmol.x = collide.x - ((t_cone*)cone)->position.x;
  narmol.y = collide.x - ((t_cone*)cone)->position.x;
  narmol.z = collide.y - ((t_cone*)cone)->position.y;
  narmol.x = narmol.x - narmol.x * ((t_cone*)cone)->focus.x
    - narmol.x * ((t_cone*)cone)->focus.x * C(tan(((t_cone*)cone)->angle));
  narmol.y = narmol.y - narmol.y * ((t_cone*)cone)->focus.y
    - narmol.y * ((t_cone*)cone)->focus.y * C(tan(((t_cone*)cone)->angle));
  narmol.z = narmol.z - narmol.z * ((t_cone*)cone)->focus.z
    - narmol.z * ((t_cone*)cone)->focus.z * C(tan(((t_cone*)cone)->angle));
  return (narmol);
}

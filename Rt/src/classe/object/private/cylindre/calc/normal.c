/*
** normal.c<3> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon Jun  3 01:23:44 2013 vincent colliot
** Last update Mon Jun  3 01:41:32 2013 vincent colliot
*/

t_3d	normal_cylindre(void *cylindre, t_3d collide)
{
  t_3d	narmol;

  narmol.x = collide.x - ((t_cylindre*)cylindre)->position.x;
  narmol.y = collide.x - ((t_cylindre*)cylindre)->position.x;
  narmol.z = collide.y - ((t_cylindre*)cylindre)->position.y;
  narmol.x = narmol.x - narmol.x * ((t_cylindre*)cylindre)->focus.x;
  narmol.x = narmol.y - narmol.y * ((t_cylindre*)cylindre)->focus.y;
  narmol.z = narmol.z - narmol.z * ((t_cylindre*)cylindre)->focus.z;
  return (narmol);
}

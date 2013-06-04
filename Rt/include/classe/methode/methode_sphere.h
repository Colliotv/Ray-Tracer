/*
** methode_sphere.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 15:02:25 2013 vincent colliot
** Last update Tue Jun  4 14:16:28 2013 vincent colliot
*/

#ifndef M_SPHERE_H_
# define M_SPHERE_H_

	/* scan */
void	sphere_pos(void*,t_token*);
void	sphere_color(void*,t_token*);
void	sphere_rayon(void*,t_token*);

	/* collide */
t_3d	collide_sphere(void *, t_3d, t_3d, t_collide *);
t_3d	normal_sphere(void *, t_3d, t_collide*);

#endif

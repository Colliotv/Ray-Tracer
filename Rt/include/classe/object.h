/*
** object.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May 16 22:11:47 2013 vincent colliot
** Last update Mon May 27 22:43:43 2013 vincent colliot
*/

#ifndef OBJECT_H_
# define OBJECT_H_

# include "dim.h"
struct s_object;
typedef struct s_sphere{
  /* public */
  struct s_sphere	*next;
  t_3d	(*collide)(void *, t_3d, t_3d);
  t_3d	(*normal)(void *, t_3d, t_3d);
  /* private */
  t_scan *scan;
  struct s_object	*nega;
  /*int	*permtab_perlin*/
  t_3d	position;
  double rayon;
}		t_sphere;

typedef struct s_plan{
  /* public */
  t_sphere	*next;
  t_3d	(*collide)(void *, t_3d, t_3d);
  t_3d	(*normal)(void *, t_3d, t_3d);
  /* private */
  t_scan *scan;
  struct s_object	*nega;
  /*int	*permtab_perlin*/
  t_3d	position;
  t_3d	angle;
  /*penser a passer de ^ a
>*/float d;
}		t_plan;

typedef struct s_object{
  /* public */
  t_object	*next;
  t_3d	(*collide)(void *, t_3d, t_3d);
  t_3d	(*normal)(void *, t_3d, t_3d);
  /* private */
  t_scan *scan;
  struct s_object	*nega;
  /*int	*permtab_perlin*/
}		t_object;

# define CLASS_OBJECT

#endif

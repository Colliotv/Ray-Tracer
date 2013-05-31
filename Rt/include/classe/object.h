/*
** object.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May 16 22:11:47 2013 vincent colliot
** Last update Thu May 30 23:00:07 2013 vincent colliot
*/

#ifndef OBJECT_H_
# define OBJECT_H_

# include "xml_scan.h"
# include "dim.h"
struct s_object;
typedef struct s_sphere{
  /* public */
  void	*next;
  t_3d	(*collide)(void *, t_3d, t_3d);
  t_3d	(*normal)(void *, t_3d, t_3d);
  /* private */
  t_token_scan *scan;
  struct s_object	*nega;
  /*int	*permtab_perlin*/
  t_3d	position;
  double rayon;
}		t_sphere;

typedef struct s_plan{
  /* public */
  void	*next;
  t_3d	(*collide)(void *, t_3d, t_3d);
  t_3d	(*normal)(void *, t_3d, t_3d);
  /* private */
  t_token_scan *scan;
  struct s_object	*nega;
  /*int	*permtab_perlin*/
  t_3d	position;
  t_3d	angle;
  /*penser a passer de ^ a
>*/float d;
}		t_plan;

typedef struct s_object{
  /* public */
  struct s_object	*next;
  t_3d	(*collide)(void *, t_3d, t_3d);
  t_3d	(*normal)(void *, t_3d, t_3d);
  /* private */
  t_token_scan *scan;
  struct s_object	*nega;
  /*int	*permtab_perlin*/
}		t_object;

# define CLASS_OBJECT t_object

#endif

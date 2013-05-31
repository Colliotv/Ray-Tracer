/*
** object.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May 16 22:11:47 2013 vincent colliot
** Last update Fri May 31 14:07:06 2013 vincent colliot
*/

#ifndef OBJECT_H_
# define OBJECT_H_

# include "u_color.h"
# include "xml_scan.h"
# include "dim.h"
struct s_object;
typedef struct s_cylindre{
  /* public */
  void	*next;
  t_3d	(*collide)(void *, t_3d, t_3d);
  t_3d	(*normal)(void *, t_3d, t_3d);
  /* private */
  t_token_scan *obj_scan;
  t_token_scan *scan;
  struct s_object	*nega;
  t_color	color;
  /*int	*permtab_perlin*/
  t_3d	position;
  t_3d	focus;
  double rayon;
}		t_cylindre;

typedef struct s_cone{
  /* public */
  void	*next;
  t_3d	(*collide)(void *, t_3d, t_3d);
  t_3d	(*normal)(void *, t_3d, t_3d);
  /* private */
  t_token_scan *obj_scan;
  t_token_scan *scan;
  struct s_object	*nega;
  t_color	color;
  /*int	*permtab_perlin*/
  t_3d	position;
  t_3d	focus;
  double angle;
}		t_cone;

typedef struct s_sphere{
  /* public */
  void	*next;
  t_3d	(*collide)(void *, t_3d, t_3d);
  t_3d	(*normal)(void *, t_3d, t_3d);
  /* private */
  t_token_scan *obj_scan;
  t_token_scan *scan;
  struct s_object	*nega;
  t_color	color;
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
  t_token_scan *obj_scan;
  t_token_scan *scan;
  struct s_object	*nega;
  t_color	color;
  /*int	*permtab_perlin*/
  t_3d	position;
  t_3d	focus;
  float d;
}		t_plan;

typedef struct s_object{
  /* public */
  struct s_object	*next;
  t_3d	(*collide)(void *, t_3d, t_3d);
  t_3d	(*normal)(void *, t_3d, t_3d);
  /* private */
  t_token_scan *obj_scan;
  t_token_scan *scan;
  struct s_object	*nega;
  t_color	color;
  /*int	*permtab_perlin*/
}		t_object;

# define CLASS_OBJECT t_object

	/* objects defines */
void    sphere_init(void *, t_token *);
void    plan_init(void *, t_token *);
void    cone_init(void *, t_token *);
void    cylindre_init(void *, t_token *);

#endif

/*
** collide.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Jun  1 22:59:52 2013 vincent colliot
** Last update Mon Jun  3 02:09:37 2013 vincent colliot
*/

#ifndef COLLIDE_H_
# define COLLDIE_H_

# include <stdlib.h>

# define MAX_DEGREE_LVL	2
# define K_COL		0.1

/*
 *alpha == reverb sur 0 - 1
 *gamma == transpa sur 0 -1
 *
 */

typedef struct s_collide{
  size_t	defined;
  size_t	up_to;
  double	k[MAX_DEGREE_LVL];
  t_3d		collide;
  t_3d		normal;
  t_color	color;
  double	alpha;//reverb
  double	gamma;//transparence
}		t_collide;

t_3d	collide_arrange(t_collide *, t_3d, t_3d);

# endif

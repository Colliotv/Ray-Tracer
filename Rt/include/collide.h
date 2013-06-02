/*
** collide.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sat Jun  1 22:59:52 2013 vincent colliot
** Last update Sun Jun  2 03:40:00 2013 vincent colliot
*/

#ifndef COLLIDE_H_
# define COLLDIE_H_

# include <stdlib.h>

# define MAX_DEGREE_LVL	2

typedef struct s_collide{
  size_t	defined;
  double	k[MAX_DEGREE_LVL];
  t_3d		collide;
  t_3d		normal;
}		t_collide;

t_3d	collide_arrange(t_collide *, t_3d, t_3d);

# endif

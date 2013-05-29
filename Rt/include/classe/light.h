/*
** light.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 21:46:39 2013 vincent colliot
** Last update Tue May 28 00:18:14 2013 vincent colliot
*/

#ifndef LIGHT_H_
# define LIGHT_H_

#include "dim.h"

typedef struct	s_light{
  /* public */
  struct s_light	*next;
  /*private */
  t_scan	*scan;
  t_3d	color;
  t_3d	postion;
}		t_light;

# define CLASS_LIGHT t_light;

#endif

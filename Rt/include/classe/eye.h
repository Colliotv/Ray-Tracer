/*
** eye.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May 30 22:47:54 2013 vincent colliot
** Last update Thu May 30 22:49:59 2013 vincent colliot
*/

#ifndef EYE_H_
# define EYE_H_

#include "dim.h"

typedef struct s_eye{
  t_3d	position;
  t_3d	direction;
  /* double angle ? */
}		t_eye;

# define CLASS_EYE t_eye

#endif

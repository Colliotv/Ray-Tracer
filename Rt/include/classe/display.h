/*
** display.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu May 16 22:01:55 2013 vincent colliot
** Last update Thu May 30 22:56:56 2013 vincent colliot
*/

#ifndef DISPLAY_H_
# define DISPLAY_H_

/* class */
# include "eye.h"
# include "light.h"
# include "object.h"
/* type mod */
# include "bool.h"
# include "fd.h"
/* fonctions */
#include "xml_scan.h"

typedef struct s_display{
  /* public */
  CLASS_EYE	*eye;
  CLASS_LIGHT	*lights;
  CLASS_OBJECT	*objects;
  /* private */
  t_scan	*scan;
}		t_display;

# define CLASS_DISPLAY	t_display
	/* move_to 'etape' */
# define END_PARSING	1
# define END_CALC	2

#endif

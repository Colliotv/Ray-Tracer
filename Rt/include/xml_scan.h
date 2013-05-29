/*
** xml_scan.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Wed May 29 17:15:51 2013 vincent colliot
** Last update Wed May 29 17:17:35 2013 vincent colliot
*/

#ifndef XML_SCAN_H_
# define XML_SCAN_H_

#include "fd.h"

typedef struct s_scan{
  char	*div;
  void	(*call)(void *, FD, int);
}		t_scan;

void	add_lum(void *,FD, int);
void	add_eye(void *,FD, int);
void	add_object(void *,FD, int);

#endif

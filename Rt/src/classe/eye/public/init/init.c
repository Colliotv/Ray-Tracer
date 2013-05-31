/*
** init.c<2> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 02:33:31 2013 vincent colliot
** Last update Fri May 31 02:48:37 2013 vincent colliot
*/

#include "eye.h"
#include "string.h"
#include "xmalloc.h"
#include "display.h"

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (2 + 1));
  (tab[0]).call = eye_pos;
  (tab[0]).name = "position";
  (tab[1]).call = eye_focus;
  (tab[1]).name = "direction";
  (tab[2]).call = NULL;
  (tab[2]).name = NULL;
  return (tab);
}

void	eye_init(void *eye, void *d)
{
  ((CLASS_EYE*)eye)->scan = ini_scan();
  ((CLASS_DISPLAY*)d)->eye = eye;
}

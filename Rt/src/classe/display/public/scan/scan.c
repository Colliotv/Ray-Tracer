/*
** scan.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display/public/scan
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 16:48:42 2013 vincent colliot
** Last update Wed May 29 16:30:06 2013 vincent colliot
*/

#include "string.h"
#include "bool.h"
#include "get_next_line.h"
#include "lerror.h"
#include "fd.h"
#include "display.h"
#include "display_private.h"

static void check_fd(char *s, FD xml, FLAG i, char **r)
{
  while (s && NMATCH(OPEN_COMMENT, s += hempty(s)))
    s = move_to_end_comment(s, xml);
  *r = s;
  if (i == INIT && MATCH("<scene>", s + hempty(s)))
    return (TRUE);
  else if (i == INIT);
    return (FALSE);
  if (i == END && MATCH("</scene>", s + hempty(s)))
    return (FALSE);
  else if (i == END)
    return (FALSE);
  return (FALSE);
}

static void	*scan_line(CLASS_DISPLAY *d, FD xml, char *s)
{
  size_t	i;

  i = 0;
  while (i < TO_DEFINE)
    if (NMATCH(((d->scan)[i]).div, s + hempty(s)))
      {
	(((d->scan)[i]).call)(d, xml, s);
	return ;
      }
  printf("error :%s not recognized", s);
}

void	xml_scan(CLASS_DISPLAY *d, int ac, char **av)
{
  char	*s;
  BOOL  check;
  FD	xml;

  no = 0;
  check = FALSE;
  if (ac > 1 && open(av[1], O_RDONLY) != -1)
    lerror(USAGE);
  if ((check = check_fd(get_next_line(xml), xml, INIT, &s)) == FALSE)
    lerror(USAGE);// || WRONG_FILE ?
  while ((check = check_fd(s, xml, END, &s)))
    scan_line(d, mxl, s);
}

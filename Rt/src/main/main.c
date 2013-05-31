/*
** main.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 16:29:41 2013 vincent colliot
** Last update Fri May 31 19:46:09 2013 vincent colliot
*/

#include "display.h"
#include "token.h"

int	main(int ac, char **av)
{
  (void)ac;
  (void)av;
  CLASS_DISPLAY	d;

  xml_scan(&d, ac, av);
  /* /\* d.move_to(END_PARSING); --> pour free tout ce qui est inutile *\/ */
  return (0);
}

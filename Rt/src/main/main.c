/*
** main.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 16:29:41 2013 vincent colliot
** Last update Tue May 28 18:34:20 2013 vincent colliot
*/

#include "token.h"

int	main(int ac, char **av)
{
  t_token *tok;
  char	*s;

  s = get_next_line(0);
  xml_token(&tok, s, INIT, 0);
  (void)ac;
  (void)av;
  /* CLASS_DISPLAY	d; */

  /* display_init(&d); */
  /* /\* d.move_to(END_PARSING); --> pour free tout ce qui est inutile *\/ */
  return (0);
}

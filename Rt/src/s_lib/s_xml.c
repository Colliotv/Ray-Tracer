/*
** s_xml.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue May 28 00:28:06 2013 vincent colliot
** Last update Tue May 28 18:40:27 2013 vincent colliot
*/

#include "token.h"
#include "strings.h"
#include "get_next_line.h"

char	*move_to_end_comment(char *s, FD xml)
{
  if (!NMATCH(OPEN_COMMENT, s))
    return (s);
  if (!S_IN(END_COMMENT, s))
    s = get_next_line(xml);
  if (!S_IN(END_COMMENT, s))
    while ((s = get_next_line(xml)) && !S_IN(END_COMMENT, s))
      free(s);
  if (!s)
    return (NULL);
  return (s + strslen(s, END_COMMENT) + sizeof(END_COMMENT));
}

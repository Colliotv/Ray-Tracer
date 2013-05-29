/*
** s_match.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue May 28 17:43:17 2013 vincent colliot
** Last update Tue May 28 17:44:50 2013 vincent colliot
*/

#include "strings.h"

size_t	hempty(const char *s)
{
  return (strspn(s, " \t"));
}

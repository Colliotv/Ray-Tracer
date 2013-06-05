/*
** def.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Tue Jun  4 23:57:08 2013 vincent colliot
** Last update Wed Jun  5 00:15:13 2013 vincent colliot
*/

#include <stdio.h>
#include <unistd.h>
#include "strings.h"
#include "object.h"
#include "string.h"

static void	def_error(char *s)
{
  (void)printf("in object def, error :%s not defined\n", s);
  exit(-1);
}

void	object_shining(void *o, t_token *token)
{
  char	*s;

  if ((s = xml_token(&token, "shine", RESOLVE, 0)) == NULL)
    def_error("shining");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("shining");
  (((CLASS_OBJECT*)o)->shine) = atof(s);
}

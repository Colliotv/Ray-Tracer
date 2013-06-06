/*
** def2.c for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Thu Jun  6 18:31:32 2013 vincent colliot
** Last update Thu Jun  6 18:53:37 2013 vincent colliot
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

static FLAG	deform_type(char *s)
{
  if (MATCH(s, "x"))
    return (dsX);
  if (MATCH(s, "y"))
    return (dsY);
  if (MATCH(s, "z"))
    return (dsZ);
  return (0b1000);
}

void	object_deform(void *o, t_token *token)
{
  int   d;
  char	*s;

  if ((s = xml_token(&token, "type", RESOLVE, 0)) == NULL)
    def_error("deformation");
  if ((((CLASS_OBJECT*)o)->to_deform |= (d = deform_type(s))) == (0b1000))
    def_error("deformation");
  if ((s = xml_token(&token, "space", RESOLVE, 0)) == NULL)
    def_error("deformation");
  if (d == 4)
    d = 3;
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("deformation");
  (((CLASS_OBJECT*)o)->deform[d - 1]).space
    = atof(s);
  if ((s = xml_token(&token, "scale", RESOLVE, 0)) == NULL)
    def_error("deformation");
  if (!O_IN(s + strspn(s, "-+"), "0123456789."))
    def_error("deformation");
  (((CLASS_OBJECT*)o)->deform[d - 1]).scale
    = atof(s);
}

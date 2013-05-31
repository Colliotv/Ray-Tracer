/*
** init.c<3> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 03:06:12 2013 vincent colliot
** Last update Fri May 31 13:16:40 2013 vincent colliot
*/

static void	*def_them(t_token_scan *scan, char *type, t_token *token, )
{
  CLASS_OBJECTS *o;

  while (scan->name)
    if (MATCH(scan->name, type))
      (scan->call)(&o, token);
  if (xml_token(&token, NULL, END, 0))
    perror("error in object def\n");
  return (o);
}

void	objects_init(CLASS_OBJECT **object, void *d, char *s, FD xml)
{
  t_token	*token;

  xml_token(&token, s, INIT, xml);
  *object = def_them(((CLASS_DISPLAY*)d)->objects_def,
		     xml_token(&token, "type", RESOLVE, 0),
		     token);
  ((CLASS_OBJECT*)object)->next = ((CLASS_DISPLAY*)d)->objects;
  ((CLASS_DISPLAY*)d)->objects = object;
}

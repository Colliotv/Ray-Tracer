/*
** scan.c<2> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt/src/classe/display/public/scan
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 17:11:47 2013 vincent colliot
** Last update Wed May 29 16:30:39 2013 vincent colliot
*/

static void check_fd(char *s, FD xml, FLAG i, char **r)
{
  s = get_next_line(xml);
  while (s && NMATCH(OPEN_COMMENT, s += hempty(s)))
    s = move_to_end_comment(s, xml);
  *r = s;
  if (!s)
    fprintf(stderr, "no <light> close\n");
  if (!s)
    return ;
  if (i == END && MATCH("</light>", s + hempty(s)))
    return (FALSE);
  else if (i == END)
    return (FALSE);
  return (FALSE);
}

static void	*scan_line(CLASS_LIGHT *light, FD xml, char *s)
{
  t_token	*token;
  char		*name;
  size_t	i;

  name = xml_token(&token, s, INIT, xml);
  i = 0;
  while ((d->scan)[i])
    if (NMATCH(((d->scan)[i]).div, name))
      {
	(((d->scan)[i]).call)();
	return ;
      }
  (*no)++;
  printf("error :%s not recognized", name);
}

void	add_lum(void *d, FD xml, char *s)
{
  BOOL check;
  CLASS_LIGHT	*light;

  check = TRUE;
  light = xmalloc(sizeof(*light));
  light_init(light, d);
  while ((check = check_fd(s, xml, END, &s)))
    scan_line(light, mxl, s, &no);
}

/*
** init.c<6> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 13:30:13 2013 vincent colliot
** Last update Fri May 31 13:38:27 2013 vincent colliot
*/

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (3 + 1));
  (tab[0]).call = cone_pos;
  (tab[0]).name = "position";
  (tab[1]).call = cone_focus;
  (tab[1]).name = "direction";//<--- serait bien de faire des defines;;;;plus tard
  (tab[2]).call = cone_color;
  (tab[2]).name = "color";
  (tab[3]).call = cone_angle;
  (tab[3]).name = "angle";
  (tab[4]).call = NULL;
  (tab[4]).name = NULL;
  return (tab);
}

void	cone_init(void *o, void *token)
{
  t_cone	*s;

  (void)token;
  s = xmalloc(sizeof(*s));
  s->scan = ini_scan();
  s->collide = NULL;
  s->normal = NULL;
  *((T_CONE*)o) = s;
}

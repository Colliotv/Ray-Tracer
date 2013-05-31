/*
** init.c<5> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 13:27:54 2013 vincent colliot
** Last update Fri May 31 13:30:20 2013 vincent colliot
*/

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (3 + 1));
  (tab[0]).call = cylindre_pos;
  (tab[0]).name = "position";
  (tab[1]).call = cylindre_color;
  (tab[1]).name = "color";
  (tab[1]).call = cylindre_focus;
  (tab[1]).name = "direction";//<--- serait bien de faire des defines;;;;plus tard
  (tab[2]).call = NULL;
  (tab[2]).name = NULL;
  return (tab);
}

void	cylindre_init(void *o, void *token)
{
  t_cylindre	*s;

  (void)token;
  s = xmalloc(sizeof(*s));
  s->scan = ini_scan();
  s->collide = NULL;
  s->normal = NULL;
  *((T_CYLINDRE*)o) = s;
}

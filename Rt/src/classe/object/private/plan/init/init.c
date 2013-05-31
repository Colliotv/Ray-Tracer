/*
** init.c<4> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri May 31 13:19:02 2013 vincent colliot
** Last update Fri May 31 13:32:50 2013 vincent colliot
*/

static t_token_scan	*ini_scan(void)
{
  t_token_scan	*tab;

  tab = xmalloc(sizeof(*tab) * (4 + 1));
  (tab[0]).call = plan_pos;
  (tab[0]).name = "position";
  (tab[1]).call = plan_color;
  (tab[1]).name = "color";
  (tab[2]).call = plan_focus;
  (tab[2]).name = "direction";//<--- serait bien de faire des defines;;;;plus tard
  (tab[3]).call = plan_d;
  (tab[3]).name = "high";
  (tab[4]).call = NULL;
  (tab[4]).name = NULL;
  return (tab);
}

void	plan_init(void *o, void	*token)
{
  t_plan	*s;

  (void)token;
  s = xmalloc(sizeof(*s));
  s->scan = ini_scan();
  s->collide = NULL;
  s->normal = NULL;
  *((t_plan*)o) = s;
}

/*
** clic.c<3> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri Jun  7 05:08:52 2013 vincent colliot
** Last update Fri Jun  7 19:48:36 2013 vincent colliot
*/

# include "screen.h"
# include "display.h"
# include "select.h"

void	translation_plan(void *plan, FLAG move)
{
  if (move & (MRup | MRdown))
    ((t_plan*)plan)->d += TMOVE * (((move & MRup) != 0) - ((move & MRdown) != 0));
  return ;
}

void	rotation_plan(void *plan, FLAG move)
{
  t_3d	*focus;

  focus = &(((t_plan*)plan)->focus);
  if (move & (MRup | MRdown))
    focus->y += RMOVE * (((move & MRup) != 0) - ((move & MRdown) != 0));
  if (move & (MRleft | MRright))
    focus->x += RMOVE * (((move & MRright) != 0) - ((move & MRleft) != 0));
  if (move & (MRfront | MRback))
    focus->z += RMOVE * (((move & MBmore) != 0) - ((move & MBless) != 0));
}

/*
** clic.c<2> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Fri Jun  7 04:59:51 2013 vincent colliot
** Last update Fri Jun  7 19:48:21 2013 vincent colliot
*/

# include "screen.h"
# include "display.h"
# include "select.h"

void	translation_cylindre(void *cylindre, FLAG move)
{
  t_3d	*position;

  position = &(((t_cylindre*)cylindre)->position);
  if (move & (MKup | MKdown))
    position->y += TMOVE * (((move & MKup) != 0) - ((move & MKdown) != 0));
  if (move & (MKleft | MKright))
    position->x += TMOVE * (((move & MKright) != 0) - ((move & MKleft) != 0));
  if (move & (MKfront | MKback))
    position->z += TMOVE * (((move & MBmore) != 0) - ((move & MBless) != 0));
}

void	rotation_cylindre(void *cylindre, FLAG move)
{
  t_3d	*focus;

  focus = &(((t_cylindre*)cylindre)->focus);
  if (move & (MRup | MRdown))
    focus->y += RMOVE * (((move & MRup) != 0) - ((move & MRdown) != 0));
  if (move & (MRleft | MRright))
    focus->x += RMOVE * (((move & MRright) != 0) - ((move & MRleft) != 0));
  if (move & (MRfront | MRback))
    focus->z += RMOVE * (((move & MBmore) != 0) - ((move & MBless) != 0));
}

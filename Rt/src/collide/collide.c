/*
** collide.c<5> for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Sun Jun  2 03:39:27 2013 vincent colliot
** Last update Sun Jun  2 03:51:34 2013 vincent colliot
*/

#include "object.h"

static void	tab_rearrange(double *tab, size_t n)
{
  double	k;
  size_t	ki;
  size_t	i;

  if (!n)
    return ;
  k = tab[ki = (i = 0)];
  while (i < n)
    if (tab[i] < k)
      k = tab[ki = (i++)];
    else
      i++;
  tab[ki] = tab[0];
  tab[0] = k;
  tab_rearrange(tab + sizeof(*tab), n - 1);
}

t_3d	collide_arrange(t_collide *k, t_3d pos, t_3d ray)
{
  tab_rearrange(k->k, k->defined);
  return (dist_convert(pos, ray, k->k[0]));

}

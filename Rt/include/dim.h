/*
** dim.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Mon May 27 18:24:15 2013 vincent colliot
** Last update Fri May 31 15:37:52 2013 vincent colliot
*/

#ifndef DIM_H_
# define DIM_H_

typedef struct s_3d{
  double	x;
  double	y;
  double	z;
}		t_3d;

typedef struct s_2d{
  double	x;
  double	y;
}		t_2d;

typedef struct s_3i{
  int	x;
  int	y;
  int	z;
}		t_3i;

typedef struct s_2i{
  int	x;
  int	y;
}		t_2i;

	/* convert */
t_3d	convert_focus(t_3d);
#endif

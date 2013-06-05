/*
** select.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Wed Jun  5 14:05:50 2013 vincent colliot
** Last update Wed Jun  5 14:11:39 2013 vincent colliot
*/

#ifndef SELECT_H_
# define SELECT_H_

typedef struct s_select{
  t_screen	*screen;
  CLASS_DISPLAY	*d;
}		t_select;

# define EXIT 65307

# define UP		65364
# define DOWN		65362
# define LEFT		65363
# define RIGHT	        65361


#endif

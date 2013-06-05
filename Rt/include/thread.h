/*
** thread.h for  in /home/collio_v/rendu_svn/Ray-Tracer/Rt
**
** Made by vincent colliot
** Login   <collio_v@epitech.net>
**
** Started on  Wed Jun  5 00:20:59 2013 vincent colliot
** Last update Wed Jun  5 19:53:29 2013 vincent colliot
*/

#ifndef THREAD_H_
# define THREAD_H_

# include <pthread.h>

typedef struct s_load_thread{
  t_screen *screen;
  CLASS_DISPLAY *d;
  int	begin;
  int	end;
  pthread_mutex_t *lock;
}		t_load_thread;

# define NTHREAD	1

# define TLD_CAST(tld) ((t_load_thread*)tld)

#endif

/*
** filtre.c for  in /home/lecorr_b//projets/RT/Ray-Tracer/Rt/src/screen_load
**
** Made by thomas lecorre
** Login   <lecorr_b@epitech.net>
**
** Started on  Tue Jun  4 15:35:59 2013 thomas lecorre
** Last update Sat Jun  8 11:39:34 2013 thomas lecorre
*/

#include "u_color.h"

void	grey(t_color *pix)
{
  float	stock;

  stock = 0.0;
  stock += (pix->rgb)[R];
  stock += (pix->rgb)[G];
  stock += (pix->rgb)[B];
  (pix->rgb)[R] = stock / 3;
  (pix->rgb)[G] = stock / 3;
  (pix->rgb)[B] = stock / 3;
}

void	sepia(t_color *pix)
{
  (pix->rgb)[R] += 80;
  (pix->rgb)[G] += 80;
}

void	negatif(t_color *pix)
{
  (pix->rgb)[R] = 255 - (pix->rgb)[R];
  (pix->rgb)[G] = 255 - (pix->rgb)[G];
  (pix->rgb)[B] = 255 - (pix->rgb)[B];
}

void	black_white(t_color *pix)
{
  float	stock;

  stock = 0.0;
  stock += (pix->rgb)[R];
  stock += (pix->rgb)[G];
  stock += (pix->rgb)[B];
  if ((stock / 3) > 60.0)
    {
      (pix->rgb)[R] = 255;
      (pix->rgb)[G] = 255;
      (pix->rgb)[B] = 255;
    }
  else
    {
      (pix->rgb)[R] = 0;
      (pix->rgb)[G] = 0;
      (pix->rgb)[B] = 0;
    }
}

t_color		filtre(t_color pix, int f)
{
  if (f == 1)
    grey(&pix);
  if (f == 2)
    sepia(&pix);
  if (f == 3)
    negatif(&pix);
  if (f == 4)
    black_white(&pix);
  return (pix);
}

//
// TORE.cc for tore in /home/cloare_q//Ray-Tracer/Rt
// 
// Made by quentin cloarec
// Login   <cloare_q@epitech.net>
// 
// Started on  Fri Jun  7 18:29:29 2013 quentin cloarec
// Last update Fri Jun  7 18:30:44 2013 quentin cloarec
//

// L'EQUATION DU TORE EN CPP. JE COMPRENDS PAS GRAND CHOSE PEUT ETRE QUE CA TE DIRA PLUS DE CHOSE QU'A MOI...

tore::tore (double minusR, double majorR):
  objet ()
{
  this->minusR = minusR;
  this->majorR = majorR;
}

tore::~tore ()
{
}

double
tore::intersection (rayon * r, double i[4])
{

  double t;
  double dist;
  double p[4];

  double a;
  double b;
  double c;
  double d;
  double e;
  double roots[4] = { 0.0, 0.0, 0.0, 0.0 };
  int nbRoots = 0;

  double pos[4];
  double dir[4];
  double pos2[4];
  double dir2[4];

  r->getOrigin(pos);
  r->getDirection(dir);

  trans->doInvTransformation(pos2,pos);
  trans->doInvTransformation(dir2,dir);

  double tmpA = dir2[0] * dir2[0] + dir2[1] * dir2[1] + dir2[2] * dir2[2];
  double tmpB =
    2.0 * (dir2[0] * pos2[0] + dir2[1] * pos2[1] + dir2[2] * pos2[2]);
  double tmpC =
    pos2[0] * pos2[0] + pos2[1] * pos2[1] + pos2[2] * pos2[2] +
    majorR * majorR - minusR * minusR;

  double tmp = 4.0 * majorR * majorR;
  double tmpD = tmp * (dir2[0] * dir2[0] + dir2[2] * dir2[2]);
  double tmpE = tmp * 2 * (dir2[0] * pos2[0] + dir2[2] * pos2[2]);
  double tmpF = tmp * (pos2[0] * pos2[0] + pos2[2] * pos2[2]);

  a = tmpA * tmpA;
  b = 2.0 * tmpA * tmpB;
  c = 2.0 * tmpA * tmpC + tmpB * tmpB - tmpD;
  d = 2.0 * tmpB * tmpC - tmpE;
  e = tmpC * tmpC - tmpF;

  Polynomial poly (a, b, c, d, e);
  nbRoots = poly.SolveQuartic (roots);

  if (!nbRoots)
    dist = MAXDOUBLE;
  else
    {

      t = MAXDOUBLE;
      for (int ii = 0; ii < nbRoots; ii++)
        {
          if (roots[ii] > epsilon && roots[ii] < t)
            t = roots[ii];
        }

      p[0] = t * dir2[0] + pos2[0];
      p[1] = t * dir2[1] + pos2[1];
      p[2] = t * dir2[2] + pos2[2];
      p[3] = 1.0;

      if (t==MAXDOUBLE)
	dist = MAXDOUBLE;
      else
        dist = distance (p, pos2);

      trans->doTransformation(i,p);
    }

  return dist;
}

void
tore::normale (double p[4],rayon * r, double laNormale[4])
{

  double p2[4];
  double k;

  trans->doInvTransformation(p2,p);

  k =
    4 * (p2[0] * p2[0] + p2[1] * p2[1] + p2[2] * p2[2] + majorR * majorR -
         minusR * minusR);

  laNormale[0] = p2[0] * k - 8 * majorR * majorR * p2[0];
  laNormale[1] = p2[1] * k;
  laNormale[2] = p2[2] * k - 8 * majorR * majorR * p2[2];
  laNormale[3] = 0;

  corrigerNormale (laNormale, p2, r);

}

#include "capsule.h"
#include <math.h>

Capsule::Capsule(const Vector& c, double _rayon, double _taille, int _nbPoints)
{
  centre = c;
  rayon = _rayon;
  taille = _taille;
  nbPoints = _nbPoints;
}

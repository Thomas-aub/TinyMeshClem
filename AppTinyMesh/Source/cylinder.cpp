#include "cylinder.h"
#include <math.h>

Cylinder::Cylinder(const Vector& c, double _rayon, double _taille, int _nbPoints)
{
  centre = c;
  rayon = _rayon;
  taille = _taille;
  nbPoints = _nbPoints;
  generatePoints();
}

void Cylinder::generatePoints(){
    double sectorStep = 2*M_PI/nbPoints;
    double sectorAngle;
    points.push_back(Vector(0,-taille,0));
    points.push_back(Vector(0,taille,0));
    for(int i =0; i<= nbPoints; i++){
        sectorAngle = i * sectorStep;
        points.push_back(CylinderPolaire(sectorAngle, -taille));
        points.push_back(CylinderPolaire(sectorAngle, taille));

    }
}
Vector Cylinder::CylinderPolaire(double i, double j)
{
    return Vector(
            centre[0] + rayon * cos(i),
            centre[1] + j  ,
            centre[2] + rayon * sin(i));
}

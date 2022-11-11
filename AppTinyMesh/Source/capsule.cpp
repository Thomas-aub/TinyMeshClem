#include "capsule.h"
#include <math.h>

Capsule::Capsule(const Vector& c, double _rayon, double _taille, int _nbPoints)
{
  centre = c;
  rayon = _rayon;
  taille = _taille;
  nbPoints = _nbPoints;
  generatePoints();
}


void Capsule::generatePoints(){
   for(int i =0; i< nbPoints; i++){
       for (int j = 0 ; j < nbPoints ; j++){
           points.push_back(capsulePolaire(i,j));
        }
   }
}
Vector Capsule::capsulePolaire(int i, int j){
    const double stepI = (2.0 * M_PI) /double(nbPoints-1); // pour l'angle sur i, dans [0, 2pi]
    const double stepJ =  M_PI / double(nbPoints-1); // pour l'angle sur j, dans [-pi/2, pi/2]
    double theta = M_PI /2.0 - double(i) * stepI;
    double phi = double(j) * stepJ;
    if(sin(theta)>=0 ){
    return (Vector(
                double(centre[0]) + rayon * cos(theta) * cos(phi),
                double(centre[1]) + rayon * cos(theta) * sin(phi),
                double(taille +  centre[2]) + rayon * sin(theta)));
    }
    return (Vector(
                double(centre[0]) + rayon * cos(theta) * cos(phi),
                double(centre[1]) + rayon * cos(theta) * sin(phi),
                double(- taille + centre[2]) + rayon * sin(theta)));
}

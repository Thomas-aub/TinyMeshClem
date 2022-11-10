#include "sphere.h"
#include <math.h>

Sphere::Sphere(const Vector& c, double r)
{
  centre = c;
  rayon = r;
  nbPoints = 50;
  generatePoints();
}

Sphere::Sphere(const Vector& c, double r, int n)
{
  centre = c;
  rayon = r;
  nbPoints = n;
  generatePoints();
}

void Sphere::generatePoints(){
   for(int i =0; i< nbPoints; i++){
       for (int j = 0 ; j < nbPoints ; j++){
           points.push_back(SpherePolaire(i,j));
        }
   }
}
Vector Sphere::SpherePolaire(int i, int j){
    const double stepI = (2.0 * M_PI) /double(nbPoints-1); // pour l'angle sur i, dans [0, 2pi]
    const double stepJ =  M_PI / double(nbPoints-1); // pour l'angle sur j, dans [-pi/2, pi/2]
    double theta = M_PI /2.0 - double(i) * stepI;
    double phi = double(j) * stepJ;
    return (Vector(
                double(centre[0]) + rayon * cos(theta) * cos(phi),
                double(centre[1]) + rayon * cos(theta) * sin(phi),
                double(centre[2]) + rayon * sin(theta)));
}

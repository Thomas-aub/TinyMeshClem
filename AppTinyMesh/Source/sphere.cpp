#include "sphere.h"
#include <math.h>

 //!< Empty sphere.
/*
const int Box::edge[24] =
{
  0,1,2,3,4,5,6,7,
  0,2,1,3,4,6,5,7,
  0,4,1,5,2,6,3,7
};

const Vector Box::normal[6] =
{
  Vector(-1.0,0.0,0.0),
  Vector(0.0,-1.0,0.0),
  Vector(0.0,0.0,-1.0),
  Vector(1.0,0.0,0.0),
  Vector(0.0, 1.0,0.0),
  Vector(0.0,0.0,1.0)
};
*/

/*
 * position point sur sphere
 * x = rayon * cos phi * cos teta
 * y = rayon * cos phi * sin teta
 * z = rayon * sin phi
*/

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

/*
    double theta = 2.0*M_PI*double(i)/nbPoints;
    double phi = -M_PI/2.0 + double(j)*M_PI/(double(nbPoints));
*/
    return (Vector(
                double(centre[0]) + rayon * cos(theta) * cos(phi),
                double(centre[1]) + rayon * cos(theta) * sin(phi),
                double(centre[2]) + rayon * sin(theta)));

    //axel.paris@liris.cnrs.fr

    /*
    auto phi = M_PI * double(i + 1) / double(nbPoints);
    auto theta = 2.0 * M_PI * double(j) / double(nbPoints);
         auto x = centre[0] + rayon * std::sin(phi) * std::cos(theta);
         auto y = centre[1] + rayon * std::cos(phi);
         auto z = centre[2] + rayon * std::sin(phi) * std::sin(theta);
         return Vector(x, y, z);
         */
}

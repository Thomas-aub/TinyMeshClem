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
    double teta = 2.0*M_PI*double(i)/nbPoints;
    double phi = -M_PI/2.0 + double(j)*M_PI/(nbPoints-1);
    return (Vector(
                centre[0] + rayon * cos(teta) * cos(phi),
                centre[1] + rayon * cos(teta) * sin(phi),
                centre[2] + rayon * sin(teta)));

    //axel.paris@liris.cnrs.fr
}

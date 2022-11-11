#include "sphere.h"
#include <math.h>
/**
 * @class Sphere sphere.h
 * @brief Sphere volumic representation.
 */

/**
 * @brief Construct a new Sphere object
 *
 * @param centre Center of the sphere (Vector)
 * @param rayon Radius of the sphere
 */
Sphere::Sphere(const Vector& c, double r)
{
  centre = c;
  rayon = r;
  nbPoints = 50;
  generatePoints();
}

/**
 * @brief Construct a new Sphere object
 *
 * @param centre Center of the sphere (Vector)
 * @param rayon Radius of the sphere
 * @param nbPoints Number of points we wish to draw
 */
Sphere::Sphere(const Vector& c, double r, int n)
{
  centre = c;
  rayon = r;
  nbPoints = n;
  generatePoints();
}

/**
 * @brief Generate the points of our cylinder
 *
 */
void Sphere::generatePoints(){
   for(int i =0; i< nbPoints; i++){
       for (int j = 0 ; j < nbPoints ; j++){
           points.push_back(SpherePolaire(i,j));
        }
   }
}

/**
 * @brief Return a vector of polar coordinate
 *
 * @param i floor
 * @param j step
 */
Vector Sphere::SpherePolaire(int i, int j){
    const double stepI = (2.0 * M_PI) /double(nbPoints-1);
    const double stepJ =  M_PI / double(nbPoints-1);
    double theta = M_PI /2.0 - double(i) * stepI;
    double phi = double(j) * stepJ;
    return (Vector(
                double(centre[0]) + rayon * cos(theta) * cos(phi),
                double(centre[1]) + rayon * cos(theta) * sin(phi),
                double(centre[2]) + rayon * sin(theta)));
}

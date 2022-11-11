#include "cylinder.h"
#include <math.h>
/**
 * @class Cylinder cylinder.h
 * @brief Cylinder volumic representation.
 */

/**
 * @brief Construct a new Cylinder object
 *
 * @param centre Center of the cylinder (Vector)
 * @param rayon Radius of the cylinder
 * @param taille Height of the cylinder cylinder
 * @param nbPoints Number of points we wish to draw
 */

Cylinder::Cylinder(const Vector& c, double _rayon, double _taille, int _nbPoints)
{
  centre = c;
  rayon = _rayon;
  taille = _taille;
  nbPoints = _nbPoints;
  generatePoints();
}

/**
 * @brief Generate the points of our cylinder
 *
 */
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

/**
 * @brief Return a vector of polar coordinate
 *
 * @param i floor
 * @param j step
 */
Vector Cylinder::CylinderPolaire(double i, double j)
{
    return Vector(
            centre[0] + rayon * cos(i),
            centre[1] + j  ,
            centre[2] + rayon * sin(i));
}

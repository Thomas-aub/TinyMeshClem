#include "../Include/torus.h"
#include <math.h>
/**
 * @class Torus torus.h
 * @brief Torus volumic representation.
 */

/**
 * @brief Construct a new Torus object
 *
 * @param centre Center of the torus (Vector)
 * @param rayon Radius of the torus
 * @param taille Height of the torus cylinder
 * @param nbPoints Number of points we wish to draw
 */
Torus::Torus(const Vector& c, double inner, double outer, int stt , int sls)
{
  centre = c;
  st = stt;
  sl = sls;
  outerR = outer;
  innerR = inner;
  generatePoints();
}

/**
 * @brief Generate the points of our cylinder
 *
 */
void Torus::generatePoints(){
    for(int stack = 0; stack<=st; stack++){
        for(int slice = 0; slice<= sl; slice++){
            points.push_back(TorusPolaire(stack, slice));
        }
    }
}

/**
 * @brief Return a vector of polar coordinate
 *
 * @param i floor
 * @param j step
 */
Vector Torus::TorusPolaire(int stack, int slice){

    double sta = double(stack);
    double sli = double(slice);

    double dp = (2* M_PI)/sl;
    double dt = (2*M_PI)/st;

    double theta = dt * sta;
    double phi = dp * sli;
    return Vector(
           cos(theta) * (outerR + cos(phi) * innerR),
           sin(theta) * (outerR + cos(phi) * innerR),
           sin(phi) * innerR);
}

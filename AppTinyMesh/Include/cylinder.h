#include <iostream>
#include "mathematics.h"
#ifndef CYLINDER_H
#include <vector>

class Cylinder
{
public:
  Vector centre; // = {Vector(0.0 , 0.0, 0.0)}; //!<
  double rayon;
  double taille;
  int nbPoints;
  std::vector<Vector> points;
  Vector Vertex(int) const;

public:
  static const Cylinder Null; //!< Empty sphere.
  //Sphere();
  Cylinder(const Vector&, double, double, int);
  Vector CylinderPolaire(double, double) ;

  void generatePoints();
  //! Empty.
  ~Cylinder() {}
};
#endif // SPHERE_H






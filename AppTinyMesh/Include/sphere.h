#include <iostream>
#include "mathematics.h"
#ifndef SPHERE_H
#include <vector>

class Sphere
{
public:
  Vector centre; // = {Vector(0.0 , 0.0, 0.0)}; //!<
  double rayon;
  int nbPoints;
  std::vector<Vector> points;
  Vector Vertex(int) const;

public:
  static const Sphere Null; //!< Empty sphere.
  //Sphere();

  Sphere(const Vector&, double);
  Sphere(const Vector&, double, int);
  Vector SpherePolaire(int, int);

  void generatePoints();
  //! Empty.
  ~Sphere() {}
};
#endif // SPHERE_H






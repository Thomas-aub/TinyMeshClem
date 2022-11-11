#include <iostream>
#include "mathematics.h"
#ifndef CAPSULE_H
#include <vector>



class Capsule
{
public:
  Vector centre; // = {Vector(0.0 , 0.0, 0.0)}; //!<
  double rayon;
  double taille;
  int nbPoints;
  std::vector<Vector> points;
  Vector Vertex(int) const;

public:
  static const Capsule Null; //!< Empty sphere.
  //Sphere();
  Capsule(const Vector&, double, double, int);
  Vector capsulePolaire(int, int);

  void generatePoints();
  //! Empty.
  ~Capsule() {}
};
#endif // TORUS_H






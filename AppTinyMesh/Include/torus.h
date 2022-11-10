#include <iostream>
#include "mathematics.h"
#ifndef TORUS_H
#include <vector>



class Torus
{
public:
  Vector centre; // = {Vector(0.0 , 0.0, 0.0)}; //!<
  /*
  double rayonG;
  double rayonP;
  int nbPoints;
  */
  int st;
  int sl;
  double innerR;
  double outerR;
  std::vector<Vector> points;
  Vector Vertex(int) const;

public:
  static const Torus Null; //!< Empty sphere.
  //Sphere();

  Torus(const Vector&, double, double, int ,int);
  //Torus(const Vector&, double, double, int);
  Vector TorusPolaire(int, int);

  void generatePoints();
  //! Empty.
  ~Torus() {}
};
#endif // TORUS_H






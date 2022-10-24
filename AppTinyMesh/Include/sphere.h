
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
  /*
   *
    // Access vertexes
    Vector& operator[] (int);
    Vector operator[] (int) const;

    // Comparison
    friend int operator==(const Box&, const Box&);
    friend int operator!=(const Box&, const Box&);

    // Acces to vertices
    Vector Center() const;
    Vector Vertex(int) const;

    Vector Size() const;
    Vector Diagonal() const;
    double Radius() const;

    bool Inside(const Box&) const;
    bool Inside(const Vector&) const;

    double Volume() const;
    double Area() const;

    // Compute sub-box
    Box Sub(int) const;

    // Translation, scale
    void Translate(const Vector&);
    void Scale(double);

    friend std::ostream& operator<<(std::ostream&, const Box&);

    public:
    static const double epsilon; //!< Internal \htmlonly\epsilon;\endhtmlonly for ray intersection tests.
    static const Box Null; //!< Empty box.
    static const int edge[24]; //!< Edge vertices.
    static const Vector normal[6]; //!< Face normals.


*/

};
#endif // SPHERE_H






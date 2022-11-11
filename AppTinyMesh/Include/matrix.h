#ifndef MATRIX_H
#define MATRIX_H
#include "mathematics.h"

class Matrix
{
private:
  double matrix[9];

public:

  Matrix();
  Matrix(const Matrix &m);
  Matrix(double m[9]);
  Matrix(double a, double b, double c,
         double d, double e, double f,
         double g, double h, double i);

  Matrix operator*(const Matrix &m) const;
  Matrix operator+(const Matrix &m) const;
  Matrix operator-(const Matrix &m) const;
  Matrix operator*(float x) const;
  Matrix operator+(float x) const;
  Matrix operator-(float x) const;
  Matrix operator/(float x) const;
  Vector operator*(const Vector &v) const;


  Matrix static RotationX(double angle);
  Matrix static RotationY(double angle);
  Matrix static RotationZ(double angle);

  Matrix Transpose();

  float Determinant();

  Matrix Inverse();

  Matrix static Scale(double scale);
  Matrix static Scale(const Vector &scale);


};

#endif // MATRIX_H

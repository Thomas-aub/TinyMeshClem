#ifndef MATRIX_H
#define MATRIX_H

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

  Matrix static RotationX(double angle);
  Matrix static RotationY(double angle);
  Matrix static RotationZ(double angle);

  Matrix Transpose();

  float Determinant();

  Matrix Inverse();

  Matrix Scale(double scale);


};

#endif // MATRIX_H

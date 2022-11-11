#include <math.h>
#include "matrix.h"


Matrix::Matrix(){
    for (int i=0; i<8; i++){
        matrix[i]=0;
    }
}

Matrix::Matrix(const Matrix &m){
    for (int i=0; i<8; i++){
        matrix[i]=m.matrix[i];
    }
}

Matrix::Matrix(double m[9]){
    for (int i=0; i<8; i++){
        matrix[i]=m[i];
    }
}

Matrix::Matrix(  double a, double b, double c,
                 double d, double e, double f,
                 double g, double h, double i){
    matrix[0] = a;
    matrix[1] = b;
    matrix[2] = c;
    matrix[3] = d;
    matrix[4] = e;
    matrix[5] = f;
    matrix[6] = g;
    matrix[7] = h;
    matrix[8] = i;
}

Matrix Matrix::operator*(const Matrix& m) const {
    return Matrix(  matrix[0] * m.matrix[0] + matrix[1] * m.matrix[3] + matrix[2] * m.matrix[6],
                    matrix[0] * m.matrix[1] + matrix[1] * m.matrix[4] + matrix[2] * m.matrix[7],
                    matrix[0] * m.matrix[2] + matrix[1] * m.matrix[5] + matrix[2] * m.matrix[8],
                    matrix[3] * m.matrix[0] + matrix[4] * m.matrix[3] + matrix[5] * m.matrix[6],
                    matrix[3] * m.matrix[1] + matrix[4] * m.matrix[4] + matrix[5] * m.matrix[7],
                    matrix[3] * m.matrix[2] + matrix[4] * m.matrix[5] + matrix[5] * m.matrix[8],
                    matrix[6] * m.matrix[0] + matrix[7] * m.matrix[3] + matrix[8] * m.matrix[6],
                    matrix[6] * m.matrix[1] + matrix[7] * m.matrix[4] + matrix[8] * m.matrix[7],
                    matrix[6] * m.matrix[2] + matrix[7] * m.matrix[5] + matrix[8] * m.matrix[8]);
}

Matrix Matrix::operator*(float x) const{
    return Matrix(  matrix[0] * x, matrix[0] * x, matrix[0] * x,
                    matrix[0] * x, matrix[0] * x, matrix[0] * x,
                    matrix[0] * x, matrix[0] * x, matrix[0] * x);
}

Vector Matrix::operator*(const Vector &v) const
{
    Vector res;

    for (int i=0; i<8; i++){
        if(i <= 2){
            res[0] += matrix[i] * v[i];
        }
        if(i <= 5){
            res[1] += matrix[i] * v[i];
        }
        if(i <= 8){
            res[2] += matrix[i] * v[i];
        }
    }
    return res;
}

Matrix Matrix::operator+(const Matrix& m) const {
    return Matrix(  matrix[0] + m.matrix[0], matrix[1] + m.matrix[1], matrix[2] + m.matrix[2],
                    matrix[3] + m.matrix[3], matrix[4] + m.matrix[4], matrix[5] + m.matrix[5],
                    matrix[6] + m.matrix[6], matrix[7] + m.matrix[7], matrix[8] + m.matrix[8]);
}

Matrix Matrix::operator+(float x) const{
    return Matrix(  matrix[0] + x, matrix[0] + x, matrix[0] + x,
                    matrix[0] + x, matrix[0] + x, matrix[0] + x,
                    matrix[0] + x, matrix[0] + x, matrix[0] + x);
}

Matrix Matrix::operator-(const Matrix& m) const {
    return Matrix(  matrix[0] - m.matrix[0], matrix[1] - m.matrix[1], matrix[2] - m.matrix[2],
                    matrix[3] - m.matrix[3], matrix[4] - m.matrix[4], matrix[5] - m.matrix[5],
                    matrix[6] - m.matrix[6], matrix[7] - m.matrix[7], matrix[8] - m.matrix[8]);
}

Matrix Matrix::operator-(float x) const{
    return Matrix(  matrix[0] - x, matrix[0] - x, matrix[0] - x,
                    matrix[0] - x, matrix[0] - x, matrix[0] - x,
                    matrix[0] - x, matrix[0] - x, matrix[0] - x);
}

Matrix Matrix::operator/(float x) const{
    return Matrix(  matrix[0] / x, matrix[0] / x, matrix[0] / x,
                    matrix[0] / x, matrix[0] / x, matrix[0] / x,
                    matrix[0] / x, matrix[0] / x, matrix[0] / x);
}

Matrix Matrix::RotationX(double angle){
    return Matrix(1,0,0,0,cos(angle),-sin(angle),0,sin(angle),cos(angle));
}

Matrix Matrix::RotationY(double angle){
    return Matrix(cos(angle),0,sin(angle),0,1,0,-sin(angle),0,cos(angle));
}

Matrix Matrix::RotationZ(double angle){
    return Matrix(cos(angle),-sin(angle),0,sin(angle),cos(angle),0,0,0,1);
}

Matrix Matrix::Transpose(){
    return Matrix(matrix[0],matrix[3],matrix[6],
                  matrix[1],matrix[4],matrix[7],
                  matrix[2],matrix[5],matrix[8]);
}


Matrix Matrix::Scale(double scale){
    return Matrix(scale,0,0,0,scale,0,0,0,scale);
}

Matrix Matrix::Scale(const Vector &s)
{
    return Matrix(s[0], 0, 0,
                  0, s[1], 0,
                  0, 0, s[2]);
}

float Matrix::Determinant(){
    return matrix[0] * ( matrix[4] * matrix[8] - matrix[5] * matrix[7]) - matrix[1] * (matrix[3] * matrix[8] - matrix[5] * matrix[6]) + matrix[2] * (matrix[3] * matrix[7] - matrix[4] * matrix[6]);
}


Matrix Matrix::Inverse(){
    float det = this->Determinant();
    Matrix transpose = this->Transpose();

    Matrix adjoint = Matrix(    transpose.matrix[4]*transpose.matrix[8] - transpose.matrix[5]*transpose.matrix[7],
                                -(transpose.matrix[1]*transpose.matrix[8] - transpose.matrix[2]*transpose.matrix[7]),
                                transpose.matrix[1]*transpose.matrix[5] - transpose.matrix[2]*transpose.matrix[4],
                                -(transpose.matrix[3]*transpose.matrix[8] - transpose.matrix[5]*transpose.matrix[6]),
                                transpose.matrix[0]*transpose.matrix[8] - transpose.matrix[2]*transpose.matrix[6],
                                -(transpose.matrix[0]*transpose.matrix[5] - transpose.matrix[2]*transpose.matrix[3]),
                                transpose.matrix[3]*transpose.matrix[7] - transpose.matrix[4]*transpose.matrix[6],
                                -(transpose.matrix[0]*transpose.matrix[7] - transpose.matrix[1]*transpose.matrix[7]),
                                transpose.matrix[0]*transpose.matrix[4] - transpose.matrix[1]*transpose.matrix[3]
            );

    Matrix inverse;
    for (int i=0; i<8; i++){
        inverse.matrix[i] = adjoint.matrix[i]/det;
    }

    return inverse;

}
































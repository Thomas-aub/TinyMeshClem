#include "../Include/torus.h"
#include <math.h>

Torus::Torus(const Vector& c, double inner, double outer, int stt , int sls)
{
  centre = c;
  st = stt;
  sl = sls;
  outerR = outer;
  innerR = inner;
  generatePoints();
}
void Torus::generatePoints(){
    for(int stack = 0; stack<=st; stack++){
        for(int slice = 0; slice<= sl; slice++){
            points.push_back(TorusPolaire(stack, slice));
        }
    }
}
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

/*
                2*std::pow(cos(theta),3) * (outerR + cos(phi) * innerR),
                1*std::pow(sin(theta),3) * (outerR + cos(phi) * innerR),
                sin(phi) * innerR);
                            */
}

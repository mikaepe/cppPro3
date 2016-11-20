/* testing classes in c++
 */

#ifndef POINT_HPP
#define POINT_HPP

#include "integrate.cpp"

class Point{
  private:
    double x;			 	// Data members
    double y;
  public:
    Point(double xx = 0.0, double yy = 0.0) : x(xx), y(yy) {}
    double X() const {return x;}
    double Y() const {return y;}
    void print() {
      std::cout << "[" << x << "," << y << "]" << std::endl;
    }

    // THE FUNCTION TO BE INTEGRATED AS TEST: (var tvungen att ta static because reasons)
    static double fx(double t)
    {
      return t*t;
    }

    // TESTA OM ASI FRÅN INTEGRATE FUNKAR:
    double integr8(double a,double b){
      double res, tol;
      tol = 1e-6;
      res = integrate(a,b,tol,&fx);
      return res;
    }

    // OPERATOR OVERLOADING

};

#endif

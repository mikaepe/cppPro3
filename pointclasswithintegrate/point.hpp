/* testing:
 * a basic class with ASI-integral and Newtonsolver
 */

#ifndef POINT_HPP
#define POINT_HPP

#include "integrate.cpp"
#include "newtsolve.cpp"

class Point{
  private:
    double x;
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

    // FUNCTION FOR TESTING NEWTONSOLVER
    static double fquad(double t)
    {
      return (t-1.0)*(t-3.0);
    }

    // DERIVATIVE FOR TESTING NEWTONSOLVER
    static double dfquad(double t)
    {
      return 2.0*t - 4.0;
    }

    // TESTA OM ASI FRÅN INTEGRATE FUNKAR:
    double integr8(double a,double b){
      double res, tol;
      tol = 1e-6;
      res = integrate(a,b,tol,&fx);
      return res;
    }

    double solve(double guess) {
      double res, tol = 1e-6;
      res = newtsolve(guess,tol,&fquad,&dfquad);
      return res;
    }

};

#endif

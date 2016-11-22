/* testing:
 * a basic class
 */

#ifndef POINT_HPP
#define POINT_HPP

class Point;
typedef (Point::*fctnPtr)(double);
//double asi(double a, double b, double tol, double , double A* p);

#include "asi2.cpp"
// #include "newtsolve.cpp"

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


    // ------------------------------------------------------------

    // Point p(-1,1) fås -x^2 + x
    double fquad2(double t)
    {
      return -x*t*t + y*t;
    }

    double dfquad2(double t)
    {
      return 2.0*x*t + y;
    }

    /* THIS IS WHAT I WANT TO DO
    double integr8(double a,double b){
      double res, tol;
      tol = 1e-2;
      res = asi(a,b,tol,&fquad2);
      return res;
    }
    */

};

#endif

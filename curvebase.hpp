#ifndef CURVEBASE_HPP
#define CURVEBASE_HPP

#include <cmath>
#include <iostream>



class Curvebase {
  
  protected:
    double a;
    double b;
    
    //int rev; // orientation of the curve

    virtual double xp(double p) = 0;	//parametrized by user
    virtual double yp(double p) = 0;	//parametrized by user
    virtual double dxp(double p) = 0;	//dx(p)/dp for arc length
    virtual double dyp(double p) = 0;	//dy(p)/dp for arc length

    double i2Simpson(double a, double b);
    double iSimpson(double a, double b); 
    double dL(double t);			// integrand for arc length
  
  public:
    double length;
    Curvebase(); 			//default constructor
    virtual double x(double s); 	//parametrized by normalized arc length
    virtual double y(double s); 	//parametrized by normalized arc length

    // TODO Move to protected, public only for testing
    double integrate(double a, double b);
    double newtonsolve(double p0, double s);
};

#endif		// CURVEBASE_HPP

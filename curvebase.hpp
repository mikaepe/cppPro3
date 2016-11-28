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




/* xLine: curves for lines with constant y
 * constructor: xi - start-x, xf - end-x, y0 - constant y
 * overwrite integrate, xp, yp, dxp, dyp, x(s) and y(s)
 */

/*
class xLine: public Curvebase{
  
  public:
    xLine(double xi, double xf, double y0);
    double x(double s); //arc length parametrization
    double y(double s); //arc length parametrization
  
  protected:
    double yConst;
    double xp(double p); // { return p; }
    double yp(double p); // { return yConst; }
    double dxp(double p); // { return 1; }
    double dyp(double p); // { return 0; }
    double integrate(double a, double b); //arc length integral
};




 * yLine: curves for lines with constant x
 * constructor: y0 - start-y, y1 - end-y, xC - constant x
 * overwrite integrate, xp, yp, dxp, dyp, x(s) and y(s)
 *
class yLine: public Curvebase{
  public:
    yLine(double yy0, double yy1, double xxC);
    double x(double s); //arc length parametrization
    double y(double s); //arc length parametrization
  protected:
    double xC;
    double xp(double p);
    double yp(double p);  
    double dxp(double p);
    double dyp(double p); 
    double integrate(double a, double b); //arc length integral
};




class fxCurve: public Curvebase{
  public: 
    fxCurve(double xx0, double xx1);	// Constructor

  protected:
    double xp(double p);
    double yp(double p);
    double dxp(double p);
    double dyp(double p);
};

*/

#endif		// CURVEBASE_HPP

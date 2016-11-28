#ifndef XLINE_HPP
#define XLINE_HPP

#include <cmath>
#include <iostream>



/* xLine: curves for lines with constant y
 * constructor: xi - start-x, xf - end-x, y0 - constant y
 * overwrite integrate, xp, yp, dxp, dyp, x(s) and y(s)
 */
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


#endif		// XLINE_HPP

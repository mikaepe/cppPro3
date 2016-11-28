#ifndef YLINE_HPP
#define YLINE_HPP


/* yLine: curves for lines with constant x
 * constructor: y0 - start-y, y1 - end-y, xC - constant x
 * overwrite integrate, xp, yp, dxp, dyp, x(s) and y(s)
 */
class yLine: public Curvebase{
  public:
    
    yLine(double yy0, double yy1, double xxC);
    ~yLine();

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


#endif		// YLINE_HPP

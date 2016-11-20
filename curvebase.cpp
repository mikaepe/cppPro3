
#include<iostream>
#include"asi.cpp"


class Curvebase {
  protected:
    double pmin;
    double pmax;
    double a;
    double b;
    int rev; // orientation of the curve
    double length;

    virtual double xp(double p) = 0;	//parametrized by user 
    virtual double yp(double p) = 0;	//parametrized by user
    virtual double dxp(double p) = 0;	//dx(p)/dp for arc length
    virtual double dyp(double p) = 0;	//dy(p)/dp for arc length
    double integrate(double a, double b); //arc length integral
  
  public:
    Curvebase() {}; 			//default constructor
    virtual double x(double s); 	//parametrized by normalized arc length
    virtual double y(double s); 	//parametrized by normalized arc length

};

// TODO use integration from project 1 to do arc length integration (see p 10 inheritance slides)
double Curvebase::integrate(double a, double b){
  return 0;
}

// do arc length parametrization
// TODO compute p by Newtons method (see lecture 06) and return xp(p)
double Curvebase::x(double s){
  return 0;
}

// do arc length parametrization
// TODO compute p by Newtons method (see lecture 06) and return yp(p)
double Curvebase::y(double s){
  return 0;
}






/* xLine: curves for lines with constant y
 * constructor: xi - start-x, xf - end-x, y0 - constant y 
 * overwrite integrate, xp, yp, dxp, dyp, x(s) and y(s)
 */
class xLine: public Curvebase{
  public:
    xLine(double xi, double xf, double y0){
      xStart = xi;
      xStop = xf;		//TODO use initialization lists instead??
      yConst = y0;
      length = xf-xi;
    }
    double x(double s); //arc length parametrization
    double y(double s); //arc length parametrization

  protected:
    double xStart;
    double xStop;
    double yConst;
    double xp(double p) { return p; }
    double yp(double p) { return yConst; }
    double dxp(double p) { return 1; }
    double dyp(double p) { return 0; }
    double integrate(double a, double b); //arc length integral
};

double xLine::integrate(double a, double b){
  return (b-a);
};

// do arc length parametrization
double xLine::y(double s){
    return yConst;
};

// do arc length parametrization
double xLine::x(double s){
    return xStart+s*length;
};







/* yLine: curves for lines with constant x
 * constructor: yi - start-y, yf - end-y, x0 - constant x 
 * overwrite integrate, xp, yp, dxp, dyp, x(s) and y(s)
 */
class yLine: public Curvebase{
  public:
    yLine(double yi, double yf, double x0){
      yStart = yi;
      yStop = yf;
      xConst = x0;
      length = yf-yi;
    }
    double x(double s); //arc length parametrization
    double y(double s); //arc length parametrization
  protected:
    double yStart;
    double yStop;
    double xConst;
    double xp(double p){ return xConst; }
    double yp(double p){ return p; }
    double dxp(double p){ return 0; }
    double dyp(double p){ return 1; }
    double integrate(double a, double b); //arc length integral
};

double yLine::integrate(double a, double b){
  return (b-a);
};

// do arc length parametrization
double yLine::x(double s){
  return xConst;
};

// do arc length parametrization
double yLine::y(double s){
  return yStart+s*length;
};







class fCurve: public Curvebase{
    // konstruktor: start-x, skift-x, slut-z
    // overwrite xp, yp, dxp, dyp
};

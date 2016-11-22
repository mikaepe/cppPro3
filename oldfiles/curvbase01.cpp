
#include<cmath>
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




/* xQuad: curves y = c2*x^2+c1*x+c0
 * constructor: x0,x1 - interval boundaries for x: [x0,x1]
 * overwrite xp, yp, dxp, dyp, x(s), y(s), integrate etc... TODO
 */
class xQuad: public Curvebase {
  public:
    xQuad(double c0, double c1, double c2, double x0, double x1)
    {
      c0_ = c0; c1_ = c1; c2_ = c1; x0_ = x0; x1_ = x1;
    }
    double x(double s);		// curve in normalized coordinate
    double y(double s);		// curve in normalized coordinate

    double integrate(double a, double b);	//arc length integral

  protected:
    double c0_, c1_, c2_, x0_, x1_;
    double xp(double p) {return p;}
    double yp(double p) {return c2_*p*p + c1_*p + c0_;}
    double dxp(double p) {return 1;}
    double dyp(double p) {return 2*c2_*p + c1_;}

    static double dL(double p)
    {

      // TODO this is what we want: 
      //return sqrt(dxp(p)*dxp(p) + dyp(p)*dyp(p));

      return sqrt((2*p - 3)*(2*p - 3) + 1);
    }

};

// TODO fix all this
double xQuad::integrate(double a, double b){

  double L, tol = 1e-4;
  L = asi(x0_,x1_,tol,&dL);
  return L;

}

// TODO fix all this
double xQuad::x(double s){
  return x0_ + s*(x1_-x0_);
}

// TODO fix all this
double xQuad::y(double s){
  double xx;
  xx = x0_ + s*(x1_-x0_);
  return c2_*xx*xx + c1_*xx + c2_;
}





class fCurve: public Curvebase{
    // konstruktor: start-x, skift-x, slut-z
    // overwrite xp, yp, dxp, dyp
};

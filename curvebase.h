
#ifndef CURVEBASE_H
#define CURVEBASE_H


#include<cmath>
#include<iostream>

class Curvebase {

protected:

    //double pmin;
    //double pmax;

    double a;
    double b;
    int rev; // orientation of the curve
    double length;

    virtual double xp(double p) = 0;	//parametrized by user
    virtual double yp(double p) = 0;	//parametrized by user
    virtual double dxp(double p) = 0;	//dx(p)/dp for arc length
    virtual double dyp(double p) = 0;	//dy(p)/dp for arc length

    /* integrate(double a, double b) and its supporting functions:
     * all is directly taken from project 1
     */

    //double mid(double a, double b) {return 0.5*(a+b);}
    // TODO tog bort mid, känns som onödig overhead

    double i2Simpson(double a, double b) {
        return iSimpson(a,0.5*(a+b)) + iSimpson(0.5*(a+b),b);
    }

    double iSimpson(double a, double b) {
        return ((b-a)/6.0)*(dL(a)+4.0*dL(0.5*(a+b)) + dL(b));
    }
    double dL(double t){ 		//integrand for the length integral
        return sqrt(dxp(t)*dxp(t)+dyp(t)*dyp(t));
    }



public:
    Curvebase() {}; 			//default constructor
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

/* yLine: curves for lines with constant x
 * constructor: y0 - start-y, y1 - end-y, xC - constant x
 * overwrite integrate, xp, yp, dxp, dyp, x(s) and y(s)
 */
class yLine: public Curvebase{
public:
    yLine(double yy0, double yy1, double xxC) : y0(yy0), y1(yy1), xC(xxC) {
        length = yy1 - yy0;
    }
    double x(double s); //arc length parametrization
    double y(double s); //arc length parametrization
protected:
    double y0;
    double y1;
    double xC;
    double xp(double p){ return xC; }
    double yp(double p){ return p; }
    double dxp(double p){ return 0; }
    double dyp(double p){ return 1; }
    double integrate(double a, double b); //arc length integral
};

/* xQuad: curves y = c2*x^2+c1*x+c0
 *
 * constructor:	c2, c1, c0 coefficients for quadratic curve
 * 		x0,x1 - interval boundaries for x: [x0,x1]
 *
 * overwrite xp, yp, dxp, dyp, x(s), y(s), etc... TODO
 */
class xQuad: public Curvebase {
public:
    xQuad(double cc2, double cc1, double cc0, double xx0, double xx1) :
            c2(cc2), c1(cc1), c0(cc0), x0(xx0), x1(xx1) {
        length = integrate(x0,x1);
        std::cout << length << std::endl;
    }
    //double x(double s);		// curve in normalized coordinate
    //double y(double s);		// curve in normalized coordinate

    //double integrate(double a, double b);	//arc length integral

protected:
    double c2, c1, c0, x0, x1;
    double xp(double p) {return p;}
    double yp(double p) {return c2*p*p + c1*p + c0;}
    double dxp(double p) {return 1;}
    double dyp(double p) {return 2*c2*p + c1;}
};

class fCurve: public Curvebase{
    // konstruktor: start-x, skift-x, slut-z
// overwrite xp, yp, dxp, dyp
};



#endif


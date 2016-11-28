


#include <cmath>
#include <iostream>
#include "curvebase.hpp"



Curvebase::Curvebase() {}; // Default constructor

// Integration from project 1

double Curvebase::i2Simpson(double a, double b) {
  return iSimpson(a,0.5*(a+b)) + iSimpson(0.5*(a+b),b);
}

double Curvebase::iSimpson(double a, double b) {
  return ((b-a)/6.0)*(dL(a)+4.0*dL(0.5*(a+b)) + dL(b));
}

double Curvebase::dL(double p) {
  return sqrt(dxp(p)*dxp(p) + dyp(p)*dyp(p));
}

double Curvebase::integrate(double a, double b){

  double tolI = 1e-8;
  double I = 0, I1, I2, errest;
  int node = 1;

  while (true) {
    I1 = iSimpson(a,b);
    I2 = i2Simpson(a,b); 
    errest = std::abs(I1-I2);
    if (errest < 15*tolI) { //if leaf
      I += I2;
      while (node % 2 != 0) { // while uneven node

	if (node == 1) { 
	  return I; // return if we are back at root again
	}

	node = 0.5*node;	
	a = 2*a-b;
	tolI *= 2;
      }
      // First even node: go one node up - go to right child
      //node = 0.5*node;
      b = 2*b-a;
      //node = 2*node+1;
      node = node+1;	// TODO ändrat här..... ok?
      a = 0.5*(a+b);
    } else { //if not a leaf: go to left child
      node *= 2;
      b = 0.5*(a+b);
      tolI *= 0.5;
    }
  }
  return I;
}

/* Newton solver for equation f(p) = l(p) - s*l(b)
 * input: p0 is initial guess for Newtons method.
 */
double Curvebase::newtonsolve(double p0, double s) {

  int iter = 0, maxiter = 150;
  double tolN = 1e-6;
  double err = 10.0;
  double p1,p;
  p = p0;
  while (err > tolN && iter < maxiter) {

    p1 = p - (integrate(a,p)-s*length)/dL(p);
    err = fabs(p1 - p);
    p = p1; iter++;
  }

  if (iter == maxiter) {
    std::cout << "No convergence in Newton solver" << std::endl;
  }

  return p;
}




// do arc length parametrization
// TODO compute p by Newtons method (see lecture 06) and return xp(p)
double Curvebase::x(double s){
  double p, p0;
  //p0 = s*(b-a);
  p0 = a + s*length;	// LAGT TILL a HÄR ###############
  p = newtonsolve(p0,s);
  return xp(p);
}

// do arc length parametrization
// TODO compute p by Newtons method (see lecture 06) and return yp(p)
double Curvebase::y(double s){
  double p, p0;
  //p0 = s*(b-a);
  p0 = a + s*length;    // LAGT TILL a HÄR ################
  p = newtonsolve(p0,s);
  return yp(p);
}









// xLine ------------------------------------------

xLine::xLine(double xi, double xf, double y0) {
  a = xi;
  b = xf;
  yConst = y0;
  length = xf-xi;
}

double xLine::integrate(double a, double b){
  return (b-a);			// Arc length integral
};

double xLine::y(double s){	// Parametrized in normalized arc length coordinate
    return yConst;
};

double xLine::x(double s){	// Parametrized in normalized arc length coordinate
    return a+s*length;
};

double xLine::xp(double p) { return p; }
double xLine::yp(double p) { return yConst; }
double xLine::dxp(double p) { return 1; }
double xLine::dyp(double p) {return 0; }




// yLine -------------------------------------------

yLine::yLine(double y0, double y1, double xCc) {
  a = y0;
  b = y1;
  xC = xCc;
  length = y1 - y0;
}

double yLine::integrate(double a, double b){
  return (b-a);
};

double yLine::x(double s){
  return xC;
};

double yLine::y(double s){
  return a+s*length;
};

double yLine::xp(double p) { return xC; }
double yLine::yp(double p) { return p; }
double yLine::dxp(double p) { return 0; }
double yLine::dyp(double p) { return 1; }



// xQuad ----------------------------------------

xQuad::xQuad(double cc2, double cc1, double cc0, double xx0, double xx1) {
  c2 = cc2;
  c1 = cc1;
  c0 = cc0;
  a = xx0;
  b = xx1;
  length = integrate(a,b);
}

double xQuad::xp(double p) { return p;}
double xQuad::yp(double p) { return c2*p*p+c1*p + c0; }
double xQuad::dxp(double p) { return 1; }
double xQuad::dyp(double p) { return 2*c2*p + c1;}





// fxCurve ------------------------------------
fxCurve::fxCurve(double xx0, double xx1) {
  a = xx0;
  b = xx1;
  length = integrate(a,b);
}

double fxCurve::xp(double p) { return p; }
double fxCurve::yp(double p) {
  if (p < -3.0) {
    return 0.5/(1.0 + exp(-3.0*(p + 6.0)));
  } else {
    return 0.5/(1.0 + exp(3.0*p));
  }
}
double fxCurve::dxp(double p) { return 1.0; }
double fxCurve::dyp(double p) {
  if (p < -3.0) {
    return 6.0*exp(-3.0*(p+6))*yp(p)*yp(p);
  } else {
    return -6.0*exp(3.0*p)*yp(p)*yp(p);
  }
}






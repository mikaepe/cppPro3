#include"curvebase.h"

// Integration from project 1
double Curvebase::integrate(double a, double b){
  double tolI = 1e-4;
  double I = 0, I1, I2, errest;
  int node = 1;

  while (true) {
    I1 = iSimpson(a,b);
    I2 = i2Simpson(a,b); // TODO tog bort här
    //I2 = ((b-a)/6.0)*(dL(a)+4.0*dL(0.5*(a+b)) + dL(b)); // TODO ändrat till det här
    errest = std::abs(I1-I2);
    if (errest < 15*tolI) { //if leaf
      I += I2;
      while (node % 2 != 0) { // while uneven node

	if (node == 1) { 
	  return I; // return if we are back at root again
	}

	//node = std::floor(0.5*node); // TODO behövs floor här?
	node = 0.5*node;	// TODO ändrat här...
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
  int iter = 0, maxiter = 100;
  double tolN = 1e-4;
  double err = 10.0;
  double p1,p;
  p = p0;
  while (err > tolN && iter < maxiter) {
    // TODO change yp to integrate(blabla) and dyp to dL(p)
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
  p0 = s*(b-a);
  p = newtonsolve(p0,s);
  return xp(p);
}

// do arc length parametrization
// TODO compute p by Newtons method (see lecture 06) and return yp(p)
double Curvebase::y(double s){
  double p, p0;
  p0 = s*(b-a);
  p = newtonsolve(p0,s);
  return yp(p);
}








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






double yLine::integrate(double a, double b){
  return (b-a);
};

// do arc length parametrization
double yLine::x(double s){
  return xC;
};

// do arc length parametrization
double yLine::y(double s){
  return y0+s*length;
};






// TODO fix all this
double xQuad::x(double s){
  return x0 + s*(x1-x0);
}

// TODO fix all this
double xQuad::y(double s){
  double xx;
  xx = x0 + s*(x1-x0);
  return c2*xx*xx + c1*xx + c2;
}

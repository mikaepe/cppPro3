
#include "curvebase.hpp"
#include "yline.hpp"

// Constructor
yLine::yLine(double y0, double y1, double xCc) {
  a = y0;
  b = y1;
  xC = xCc;
  length = y1 - y0;
}

// Destructor
yLine::~yLine() {}

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



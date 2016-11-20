



#include <iostream>
#include "point.hpp"


double phi1(double t) {return t;}
double phi2(double t) {return 1-t;}


using namespace std;
int main(void){
  double t = 0.423;

  double x,y;
  x = phi1(t);
  y = phi2(t);

  cout << "t = " << t << endl;
  cout << "phi1 = " << x << endl;
  cout << "phi2 = " << y << endl;

  cout << endl;

  Point p(1.0,2.0);
  p.print();

  double f;
  f = p.fx(0.707);
  cout << "f(0.707) = " << f << endl;

  double I;
  I = p.integr8(0.0,2.0);
  cout << "integr8 = " << I << endl;

  return 0;
}

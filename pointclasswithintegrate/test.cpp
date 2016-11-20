
#include <iostream>
#include "point.hpp"

using namespace std;
int main(void){

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

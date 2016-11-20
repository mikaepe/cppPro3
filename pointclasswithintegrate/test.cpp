
#include <iostream>
#include "point.hpp"

//#include "newtsolve.cpp"

double fquad(double x){
  return (x-1.0)*(x-3.0);
}

double dfquad(double x){
  return 2.0*x - 4.0;
}


using namespace std;
int main(void){

  Point p(1.0,2.0);
  p.print();

  double f;
  f = p.fx(0.707);
  cout << "f(0.707) = " << f << endl;

  double I;
  I = p.integr8(0.0,2.0);
  cout << "integr8(0,2) = " << I << endl;
  I = p.integr8(0,1);
  cout << "integr8(0,1) = " << I << endl;

  /*
  double x1;
  x1 = newtsolve(1.123,1e-4,&fquad,&dfquad);
  cout << "root1 = " << x1 << endl;
  double x2;
  x2 = newtsolve(2.91,1e-4,&fquad,&dfquad);
  cout << "root2 = " << x2 << endl;
  */

  double root;
  root = p.solve(1.333);
  cout << "root1 = " << root << endl;
  root = p.solve(2.3333);
  cout << "root2 = " << root << endl;


  return 0;
}

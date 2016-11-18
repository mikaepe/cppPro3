
#include<iostream>
#include"integrate.cpp"

double xsquared(double x) {return x*x;}

using namespace std;

int main(void)
{
  double I;
  double tol = 1e-3;

  I = integrate(0.0, 2.0, tol, &xsquared);

  cout << "I = " << I << endl;

  int a = 4;
  a*=0.33;
  cout << a << endl;

  return 0;
}


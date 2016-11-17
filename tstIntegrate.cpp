
#include<iostream>
#include"integrate.cpp"

double xsquared(double x) {return x*x;}

using namespace std;

int main(void)
{
  double I;
  double tol = 1e-3;

  I = integrate(0.0, 1.0, tol, &xsquared);

  cout << "I = " << I << endl;

  return 0;
}


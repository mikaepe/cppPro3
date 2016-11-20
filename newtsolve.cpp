
#include"newtsolve.hpp"
#include<cmath>

// function declarations	::	::	::

double newtsolve(double xguess, double tol, fctnPtr f, fctnPtr df) 
{
  int iter = 0, maxiter = 100;
  double err = 10;
  double x1, x;
  x = xguess;

  while (err > tol && iter < maxiter) {
    x1 = x - f(x)/df(x);
    err = fabs(x1 - x);
    x = x1; iter++;
  }

  if (iter == maxiter) {
    std::cout << " No convergence in Newton solver " << std::endl;
  }

  return x;
}


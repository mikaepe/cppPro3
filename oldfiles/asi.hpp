#ifndef ASI_HPP
#define ASI_HPP

typedef double (*fctnPtr)(double);
double asi(double a, double b, double tol, fctnPtr f);

#endif

#ifndef INTEGRATE_HPP
#define INTEGRATE_HPP

typedef double (*fctnPtr)(double);
double integrate(double a, double b, double tol, fctnPtr f);

#endif

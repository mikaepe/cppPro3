#ifndef NEWTSOLVE_HPP
#define NEWTSOLVE_HPP

typedef double (*fctnPtr)(double);
double newtsolve(double xguess, double tol, fctnPtr f, fctnPtr df);

#endif

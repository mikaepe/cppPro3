#ifndef INTEGRATE_HPP
#define INTEGRATE_HPP

typedef double (*functionPointer)(double);
double integrate(double a, double b, double tol, functionPointer f);

#endif
